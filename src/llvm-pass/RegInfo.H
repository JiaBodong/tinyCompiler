#include "llvm/IR/Value.h"
#include <map>
#include <set>

using namespace llvm;


// If an instruction is defining any virtual register, then we will update its Live Range Start as well as its Live Range End as current instruction index.
//  If an instruction is using any virtual register, then we will update its Live Range End as current instruction index -1
//  If an instruction is redefining any virtual register, then we will update its LiveRangeEnd as current instruction index -1
class LiveIntervalInfo {
public:
  // 
  std::map<Value *, std::set<Instruction *>> LiveIntervals;

  // 
  void addUse(Value *Reg, Instruction *UseInst) {
    LiveIntervals[Reg].insert(UseInst);
  }

  // 
  void addDef(Value *Reg, Instruction *DefInst) {
    LiveIntervals[Reg].insert(DefInst);
  }

  // 
  std::set<Instruction *> getLiveInterval(Value *Reg) {
    return LiveIntervals[Reg];
  }

  // 
  void clear() {
    LiveIntervals.clear();
  }
};
