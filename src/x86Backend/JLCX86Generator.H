/* File generated by the BNF Converter (bnfc 2.9.4). */

#ifndef __JLC_X86_GENERATOR__
#define __JLC_X86_GENERATOR__
/* You might want to change the above name. */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Absyn.H"
#include "context.H"

#include "Skeleton.H"


// llvm dependencies
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "queue"

struct RegisterInfo{
  bool available;     //check if the register is available
  llvm::Value * value; //the value in the register
};


struct VariableInfo{
  std::string name;
  llvm::Value * value;
  int stack_location;
  std::string register_name;//current coorsponding register name
};



class JLCX86Generator : public Skeleton
{
public:
  Context globalContext;
  type_enum temp_type;
  op_enum temp_op;
 
  JLCX86Generator(): LLVM_Context_(std::make_unique<llvm::LLVMContext>()),
                      LLVM_module_(std::make_unique<llvm::Module>("JLC_llvm", *LLVM_Context_)),
                      LLVM_builder_(std::make_unique<llvm::IRBuilder<>>(*LLVM_Context_))
  {
    addExternalFunc();
  };

  ~JLCX86Generator(){

    //print stdout of x86output.s
    std::ifstream infile("x86output.s");
    std::string line;
    while (std::getline(infile, line)){
      std::cout << line << std::endl;
    }
  };
  

private:
  /* serving for generating llvm code*/
  std::unique_ptr<llvm::LLVMContext> LLVM_Context_;
  std::unique_ptr<llvm::Module> LLVM_module_;
  std::unique_ptr<llvm::IRBuilder<>> LLVM_builder_;

  llvm::Value * llvm_temp_value_;
  std::string x86_temp_value;
  std::string x86_temp_value_type;
  std::string TEMP_REG;//for eadd,emul,erel
  
  std::string x86_temp_FPregister;//reducdant, need to change
  bool isRelop = false;
  // for handle float equal
  std::string LfpReg;
  std::string RfpReg;

  bool condHasReturn = false;

  void insertContentAtBeginning(const std::string& filename, const std::string& content) {
    // stringstream 
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: Failed to open file for reading." << std::endl;
        return;
    }

    std::stringstream fileContent;
    fileContent << infile.rdbuf();
    infile.close();

    // stringstream 
    std::string newContent = content + "\n" + fileContent.str();

    // 
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return;
    }

    // stringstream 
    outfile << newContent;
    outfile.close();
  }



  // a map using for store x86 instruction code , one function name include a vector
  std::map<std::string, std::vector<std::string>> x86_function_map;
  
  // map for function name and if have function call
  std::map<std::string, bool> function_call_map;


  // map for double x86_temp_value and FP number
  std::map<std::string, std::string> x86_FP_map;

  //check if the double x86_temp_value is in the map
  bool checkDoubleFPMap(std::string x86_temp_value){
    if (x86_FP_map.find(x86_temp_value) != x86_FP_map.end()){
      return true;
    }
    return false;
  }

  // get the FP number from the map
  std::string getDoubleFPMap(std::string x86_temp_value){
    return x86_FP_map[x86_temp_value];
  }

  // add the double x86_temp_value and FP number to the map
  void addDoubleFPMap(std::string x86_temp_value, std::string FP_number){
    x86_FP_map[x86_temp_value] = FP_number;
  }
 
  // like x86_FP_map, for string
  std::map<std::string, std::string> x86_string_map;

  //check if the string x86_temp_value is in the map
  bool checkStringMap(std::string x86_temp_value){
    if (x86_string_map.find(x86_temp_value) != x86_string_map.end()){
      return true;
    }
    return false;
  }

  // get the string from the map
  std::string getStringMap(std::string x86_temp_value){
    return x86_string_map[x86_temp_value];
  }

  // add the string x86_temp_value and FP number to the map
  void addStringMap(std::string x86_temp_value, std::string FP_number){
    x86_string_map[x86_temp_value] = FP_number;
  }


  // GET _CONTEXT()
  llvm::LLVMContext &GET_CONTEXT(){
    return *LLVM_Context_;
  }
  

  //store the temp stack location for register spilling
  std::vector<int> register_spill_location;

  //each element in vector + 1
  void setTempStackSize(){
    for(int i = 0; i < register_spill_location.size(); i++){
      register_spill_location[i] += 16;
    }

  }


  // a queue to store function argument list register name
  std::queue<std::string> function_arg_queue_32;
  std::queue<std::string> function_arg_queue_64;
  std::queue<std::string> function_arg_queue_128;
  std::queue<std::string> function_arg_queue_8;

  // pop the argument register name from the queue, if Int type, pop from 32 bit register queue, if Double type, pop from 128 bit register queue
  std::string popArgFromFunctionMap(type_enum type){
    if (type == type_enum::INT||type == type_enum::BOOL){
      if (!function_arg_queue_32.empty()){
        std::string arg_name = function_arg_queue_32.front();
        function_arg_queue_32.pop();
        return arg_name;
      }
    }
    else if (type == type_enum::DOUB){
      if (!function_arg_queue_128.empty()){
        std::string arg_name = function_arg_queue_128.front();
        function_arg_queue_128.pop();
        return arg_name;
      }
    } 
    
    return "";
  }

  // after calling function, restore the function_arg_queue
  void restoreFunctionArgQueue(){
    // restore the function_arg_queue

    // clear the queue
    while (!function_arg_queue_32.empty()){
      function_arg_queue_32.pop();
    }
    while (!function_arg_queue_64.empty()){
      function_arg_queue_64.pop();
    }
    while (!function_arg_queue_128.empty()){
      function_arg_queue_128.pop();
    }
    while (!function_arg_queue_8.empty()){
      function_arg_queue_8.pop();
    }

    std::initializer_list<std::string> arg_list = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};
    for (const auto& arg : arg_list) {
        function_arg_queue_32.push(arg);
    }

    arg_list = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
    for (const auto& arg : arg_list) {
        function_arg_queue_64.push(arg);
    }

    arg_list = {"xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"};
    for (const auto& arg : arg_list) {
        function_arg_queue_128.push(arg);
    }

    arg_list = {"al", "bl", "cl", "dl", "sil", "dil", "r8b", "r9b", "r10b", "r11b"};
    for (const auto& arg : arg_list) {
        function_arg_queue_8.push(arg);
    }
  }
  

  

  // x86-64 gcc register info, 32 bit registers, dont add %
std::map<std::string, RegisterInfo> register_map_32{
  {"eax", {true, nullptr}},
  {"ebx", {true, nullptr}},
  {"ecx", {true, nullptr}},
  {"edx", {true, nullptr}},
  {"esi", {true, nullptr}},
  {"edi", {true, nullptr}}, 
  {"r8d", {true, nullptr}},
  {"r9d", {true, nullptr}},
  {"r10d", {true, nullptr}},
  {"r11d", {true, nullptr}},
  {"r12d", {true, nullptr}},
  {"r13d", {true, nullptr}},
  {"r14d", {true, nullptr}},
  {"r15d", {true, nullptr}},
};

// x86-64 gcc register info, 64 bit registers
std::map<std::string, RegisterInfo> register_map_64{
  {"rax", {true, nullptr}},
  {"rbx", {true, nullptr}},
  {"rcx", {true, nullptr}},
  {"rdx", {true, nullptr}},
  {"rsi", {true, nullptr}},
  {"rdi", {true, nullptr}},
  {"rbp", {true, nullptr}},
  {"rsp", {true, nullptr}},
  {"rip", {true, nullptr}},
  {"r8", {true, nullptr}},
  {"r9", {true, nullptr}},
  {"r10", {true, nullptr}},
  {"r11", {true, nullptr}},
  {"r12", {true, nullptr}},
  {"r13", {true, nullptr}},
  {"r14", {true, nullptr}},
  {"r15", {true, nullptr}},
};

// x86-64 gcc register info, 128 bit registers
std::map<std::string, RegisterInfo> register_map_128{
  {"xmm0", {true, nullptr}},
  {"xmm1", {true, nullptr}},
  {"xmm2", {true, nullptr}},
  {"xmm3", {true, nullptr}},
  {"xmm4", {true, nullptr}},
  {"xmm5", {true, nullptr}},
  {"xmm6", {true, nullptr}},
  {"xmm7", {true, nullptr}},
  {"xmm8", {true, nullptr}},
  {"xmm9", {true, nullptr}},
  {"xmm10", {true, nullptr}},
  {"xmm11", {true, nullptr}},
  {"xmm12", {true, nullptr}},
  {"xmm13", {true, nullptr}},
  {"xmm14", {true, nullptr}},
  {"xmm15", {true, nullptr}},
};

std::map<std::string, RegisterInfo> register_map_8{
  {"al", {true, nullptr}},
  {"bl", {true, nullptr}},
  {"cl", {true, nullptr}},
  {"dl", {true, nullptr}},
  {"sil", {true, nullptr}},
  {"dil", {true, nullptr}},
  {"r8b", {true, nullptr}},
  {"r9b", {true, nullptr}},
  {"r10b", {true, nullptr}},
  {"r11b", {true, nullptr}},
};


  // for saving the variable in the block, the last element is the current block
  // mapping from original variable name to llvm variable 
  std::vector<std::map<std::string, llvm::Value *>> block_var_map_list;

  void addBlockVarMap(){
    block_var_map_list.push_back(std::map<std::string, llvm::Value *>());
  }

  void removeBlockVarMap(){
    block_var_map_list.pop_back();
  }

  void addVarToBlockMap(std::string var_name, llvm::Value * var_value){
    block_var_map_list.back()[var_name] = var_value;
  }

  llvm::Value * getVarFromBlockMap(std::string var_name){
    for (int i = block_var_map_list.size() - 1; i >= 0; i--){
      if (block_var_map_list[i].find(var_name) != block_var_map_list[i].end()){
        return block_var_map_list[i][var_name];
      }
    }
    // it should not reach here
    std::cerr << "Error: variable " << var_name << " not found in llvm block name map" << std::endl;
    return nullptr;
  }

  // for saving the VariableInfo in the block, the last element is the current block

  std::vector<std::map<std::string, VariableInfo>> block_var_info_map_list;

  void addBlockVarInfoMap(){
    block_var_info_map_list.push_back(std::map<std::string, VariableInfo>());
  }

  void removeBlockVarInfoMap(){
    block_var_info_map_list.pop_back();
  }

  void addVarInfoToBlockMap(std::string var_name, llvm::Value * var_value, int stack_location, std::string register_name){
    block_var_info_map_list.back()[var_name] = {var_name, var_value, stack_location, register_name};
  }

  // get the VariableInfo address from the block map, so that I can change some information of the variable
  VariableInfo * getVarInfoFromBlockMap(std::string var_name){
    for (int i = block_var_info_map_list.size() - 1; i >= 0; i--){
      if (block_var_info_map_list[i].find(var_name) != block_var_info_map_list[i].end()){
        return &block_var_info_map_list[i][var_name];
      }
    }
    // it should not reach here
    std::cerr << "Error: variable " << var_name << " not found in x86 block name map" << std::endl;
    return nullptr;
  }

  
  // mapping stack location to variable name and value.
  //  each stack correspond a local block(function). when a new block is created, a new stack is created.
  // for using of function call. each time a int/float is pushed to the stack, the stack pointer will be increased by 4/8
  // for example, two init variables, a and b, a is int, b is double, then the stack will be like this:
  // [rbp-4]: a, 1
  // [rbp-(4+8)]: b, 2.0
  // record the stack top pointer
  // for saving the stack of the block
  std::vector<std::map<int, std::pair<std::string, llvm::Value *>>> block_stack_map_list;

  void addBlockStackMap(){
    block_stack_map_list.push_back(std::map<int, std::pair<std::string, llvm::Value *>>());
  }

  void removeBlockStackMap(){
    block_stack_map_list.pop_back();
  } 

  void addVarToStackMap(std::string var_name, llvm::Value * var_value){
    block_stack_map_list.back()[getStackTop() - 4] = {var_name, var_value};
  }


  // get the stack top pointer
  int getStackTop() {
      int stack_top = 0;
      if (!block_stack_map_list.empty()) {
          auto& current_map = block_stack_map_list.back();
          if (!current_map.empty()) {
              stack_top = current_map.begin()->first;
          }
      }
      return stack_top;
  }


  //get the stack location of the variable through var_name
  int getStackLocation(std::string var_name){
    for (int i = block_var_info_map_list.size() - 1; i >= 0; i--){
      if (block_var_info_map_list[i].find(var_name) != block_var_info_map_list[i].end()){
        return block_var_info_map_list[i][var_name].stack_location;
      }
    }
    // it should not reach here
    std::cerr << "Error: variable " << var_name << " not found in x86 block name map" << std::endl;
    return -1;
  }




  // check register availability from the register map
  //Int : just check the register availability in register_map, first check all the 32 bit Int registers, and then all the 64 bit Int registers
  // if no register is available, return nullptr
  std::string checkIntRegisterAvailability(){
    for (auto it = register_map_32.begin(); it != register_map_32.end(); it++){
      if (it->second.available){
        return it->first;
      }
    }
    for (auto it = register_map_64.begin(); it != register_map_64.end(); it++){
      if (it->second.available){
        return it->first;
      }
    }
    return "";
  }
  //Double : check the register availability in register_map, first check all the 128 bit Double registers, and then all the 64 bit Double registers
  // if no register is available, return nullptr
  std::string checkDoubleRegisterAvailability(){
    for (auto it = register_map_128.begin(); it != register_map_128.end(); it++){
      if (it->second.available){
        return it->first;
      }
    }

    return "";
  }

  std::string checkBoolRegisterAvailability(){
    for (auto it = register_map_8.begin(); it != register_map_8.end(); it++){
      if (it->second.available){
        return it->first;
      }
    }

    return "";
  }


  //update the register availability in register_map
  void updateRegisterAvailability(std::string register_name, bool available){
    if (register_map_32.find(register_name) != register_map_32.end()){
      register_map_32[register_name].available = available;
    }
    else if (register_map_64.find(register_name) != register_map_64.end()){
      register_map_64[register_name].available = available;
    }
    else if (register_map_128.find(register_name) != register_map_128.end()){
      register_map_128[register_name].available = available;
    }
    else if (register_map_8.find(register_name) != register_map_8.end()){
      register_map_8[register_name].available = available;

    }
    else{
      // it should not reach here
      ;
    }
  }


  //update variableinfo coorsponding to the register_name
  void updateVarInfoRegisterName(std::string var_name, std::string register_name){
    for (int i = block_var_info_map_list.size() - 1; i >= 0; i--){
      if (block_var_info_map_list[i].find(var_name) != block_var_info_map_list[i].end()){
        block_var_info_map_list[i][var_name].register_name = register_name;
        return;
      }
    }
    // it should not reach here
    std::cerr << "Error: variable " << var_name << " not found in x86 block name map" << std::endl;
  }

  //update imm value* corrsponding to the register_name
  void updateRegisterValue(llvm::Value * value,std::string register_name){
    if (register_map_32.find(register_name) != register_map_32.end()){
      register_map_32[register_name].value = value;
    }
    else if (register_map_64.find(register_name) != register_map_64.end()){
      register_map_64[register_name].value = value;
    }
    else if (register_map_128.find(register_name) != register_map_128.end()){
      register_map_128[register_name].value = value;
    }
    else{
      // it should not reach here
      std::cerr << "Error: register " << register_name << " not found in register map" << std::endl;
    }
  }



  // type conversion
  llvm::Type *convertType(type_enum type);
  // add inner/external function to the head of the ll file
  // for example, printInt, printDouble, printString, printBool
  void addExternalFunc();

  void addFuncDeclearation(Frame &frame);

  std::string spillRegister(std::string register_name, type_enum type);
  

public:
  // void visitProg(Prog *p);
  // void visitTopDef(TopDef *p);
  // void visitArg(Arg *p);
  // void visitBlk(Blk *p);
  // void visitStmt(Stmt *p);
  // void visitItem(Item *p);
  // void visitType(Type *p);
  // void visitExpr(Expr *p);
  // void visitAddOp(AddOp *p);
  // void visitMulOp(MulOp *p);
  // void visitRelOp(RelOp *p);
  
  void visitProgram(Program *p);
  void visitFnDef(FnDef *p);
  void visitArgument(Argument *p);
  void visitBlock(Block *p);
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitInitElem(InitElem *p);
  void visitAss(Ass *p);
  void visitArrayAss(ArrayAss *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitForBlk(ForBlk *p);
  void visitForLoop(ForLoop *p);
  void visitWhile(While *p);
  void visitSExp(SExp *p);
  void visitInt(Int *p);
  void visitDoub(Doub *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitIntArray(IntArray *p);
  void visitDoubArray(DoubArray *p);
  void visitBoolArray(BoolArray *p);
  void visitFun(Fun *p);
  void visitEVar(EVar *p);
  void visitEArrayLen(EArrayLen *p);
  void visitEArrayNew(EArrayNew *p);
  void visitEArray(EArray *p);
  void visitELitInt(ELitInt *p);
  void visitELitDoub(ELitDoub *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);
  // void visitListTopDef(ListTopDef *p);
  // void visitListArg(ListArg *p);
  // void visitListStmt(ListStmt *p);
  // void visitListItem(ListItem *p);
  // void visitListType(ListType *p);
  // void visitListExpr(ListExpr *p);

  // void visitInteger(Integer x);
  // void visitChar(Char x);
  // void visitDouble(Double x);
  // void visitString(String x);
  // void visitIdent(Ident x);
  // void x86CodeGen(auto F);

};


#endif
