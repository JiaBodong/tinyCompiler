#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Value.h"

#include <map>
#include <vector>

using namespace llvm;

//for build interference graph
std::map<std::string, std::set<std::string>> InterferenceGraph;
// store virtual register info, including the live interval start and end
std::map<Value *, std::pair<Instruction *, Instruction *>> LiveIntervals;
std::map<std::string, std::string> RegisterAllocation;
// x86 physical registers
std::set<std::string> AvailableRegisters = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%rbp", "%rsp"};
// traverse, find the virtual register with degree less than 8, push it to stack, and remove it from the graph
std::vector<std::string> Stack;

struct MyPass : public llvm:: PassInfoMixin<MyPass> {
public:
  MyPass();


  void analyzeInstruction(Instruction &Inst);
  void buildInterferenceGraph();
  void registerAllocation();

  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    for (BasicBlock &BB : F) {
      for (Instruction &Inst : BB) {
        // analyze instruction
        analyzeInstruction(Inst);
      }
    }
    
    buildInterferenceGraph();
    registerAllocation();
    
    return PreservedAnalyses::all();
  }
  
  
};

void analyzeInstruction(Instruction &Inst) {


    // update live interval of each virtual register
    
    // traverse operands of the instruction
    for (Use &U : Inst.operands()) {
        Value *Operand = U.get();
        // check if the operand is an instruction
        if (isa<Instruction>(Operand)) {
        Instruction *OpInst = cast<Instruction>(Operand);
            if (OpInst->hasName()) {
                // get the name of the virtual register
                StringRef RegName = OpInst->getName();
                Value* RegValue = cast<Value>(OpInst);
                //update the live interval of the virtual register
      
                // If an instruction is defining any virtual register, then we will update its Live Range Start as well as its Live Range End as current instruction index.
                //  If an instruction is using any virtual register, then we will update its Live Range End as current instruction index -1
                //  If an instruction is redefining any virtual register, then we will update its LiveRangeEnd as current instruction index -1
                if (isa<AllocaInst>(Inst) || isa<LoadInst>(Inst)) {
                    // is vr def, insert the index of the instruction
                    LiveIntervals[RegValue].first = &Inst;

                } else if (isa<StoreInst>(Inst) || isa<GetElementPtrInst>(Inst) || isa<PHINode>(Inst)) {
                    // is vr use
                    LiveIntervals[RegValue].second = &Inst;         
                }
                
                // outs() << "Virtual register " << RegName << " is used at instruction: ";
                // Inst.print(outs());
                // outs() << "\n";
            }
        }
    }
  }

  void buildInterferenceGraph() {
    for (auto &u : LiveIntervals) {
        for (auto &v : LiveIntervals) {
            if (&u != &v) {
                auto uStart = u.second.first->getDebugLoc().get();
                auto uEnd = u.second.second->getDebugLoc().get();
                auto vStart = v.second.first->getDebugLoc().get();
                auto vEnd = v.second.second->getDebugLoc().get();

                if ((uEnd >= vStart) && (vEnd >= uStart)) {
                    // 'u' and 'v' have overlapping live ranges
                    InterferenceGraph[std::string(u.first->getName())].emplace(std::string(v.first->getName()));
                    InterferenceGraph[std::string(v.first->getName())].emplace(std::string(u.first->getName()));
                }
            }
        }
    }

       // print the interference graph
    for (auto &Node : InterferenceGraph) {
      outs() << Node.first << " -> ";
      for (auto &Neighbor : Node.second) {
        outs() << Neighbor << " ";
      }
      outs() << "\n";
    }
  }

    // start register allocation
    // traverse the interference graph, and assign physical registers to virtual registers
    // using graph coloring algorithm

  void registerAllocation() {
    while (!InterferenceGraph.empty()) {
        std::string MinDegreeNode;
        int MinDegree = 8;
        for (auto &Node : InterferenceGraph) {
            if (Node.second.size() < MinDegree) {
                MinDegree = Node.second.size();
                MinDegreeNode = Node.first;
            }
        }
        Stack.push_back(MinDegreeNode);
        // break off edges
        for (auto &Neighbor : InterferenceGraph[MinDegreeNode]) {
            InterferenceGraph[Neighbor].erase(MinDegreeNode);
        }
        // InterferenceGraph.erase(MinDegreeNode);
    }
    
    
    // every time pop the top of stack, restore its place and edges(maybe not complete,because some of neighbors are still in stack)
    // then assign physical registers to this virtual registers
    while (!Stack.empty()) {
        std::string Node = Stack.back();
        Stack.pop_back();
        // restore edges
        for (auto &Neighbor : InterferenceGraph[Node]) {
            InterferenceGraph[Neighbor].emplace(Node);
        }
        // assign physical register
        for (auto &Reg : AvailableRegisters) {
            bool IsAvailable = true;
            for (auto &Neighbor : InterferenceGraph[Node]) {
                if (RegisterAllocation[Neighbor] == Reg) {
                    IsAvailable = false;
                    break;
                }
            }
            if (IsAvailable) {
                RegisterAllocation[Node] = Reg;
                break;
            }
        }
    }
    



    // print register allocation
    for (auto &Node : RegisterAllocation) {
        outs() << Node.first << " -> " << Node.second << "\n";
    }


  }


