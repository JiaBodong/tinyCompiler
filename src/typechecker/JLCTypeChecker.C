/* File generated by the BNF Converter (bnfc 2.9.4). */

/*** Visitor Design Pattern JLCTypeChecker. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "JLCTypeChecker.H"
#include "util.h"
#include "Printer.H"

#include <iostream>
#include <string>
#include <cstdlib>

#if ENABLE_TYPE_CHECK_DEBUG == 0
#undef DEBUG_PRINT
#define DEBUG_PRINT(ss)
#endif

static PrintAbsyn p = PrintAbsyn();

static const std::string checkerName = "JLCTypeChecker";


void JLCTypeChecker::visitProgram(Program *program)
{
  /* Code For Program Goes Here */
  DEBUG_PRINT( "[" + checkerName +"]" + " visiting Program");

  /* iterate through the top definitions */
  for (ListTopDef::iterator top_def = program->listtopdef_->begin() ; top_def != program->listtopdef_->end() ; ++top_def)
  {
    FnDef* fn_def = reinterpret_cast<FnDef*>(*top_def);
    if (fn_def->type_) fn_def->type_->accept(this);
    DEBUG_PRINT("\tFunction type: " + to_string(temp_type));
    // don't need to check type_, as long as the parser is correct, otherwise it will throw an error
    // it is impossible to have a function without a type

    // check function name
    visitIdent(fn_def->ident_);
    // check if the function is already declared
    if(globalContext.isExistFunction(fn_def->ident_)){
      std::cerr << "ERROR: Function " << fn_def->ident_ << " is already declared" << std::endl;
      exit(1);
    }
    // add the function to the global context
    globalContext.addFrame(fn_def->ident_);
    globalContext.currentFrameName = fn_def->ident_;

    // update the function return type
    Frame& func = globalContext.getFrame(fn_def->ident_);
    func.returnType = temp_type;
  
    // if fuction is main, check if it has int type
    if(fn_def->ident_ == "main" && temp_type != INT){
      std::cerr << "ERROR: Function main should have int type return" << std::endl;
      exit(1);
    }
    // check function arguments
    if (fn_def->listarg_) fn_def->listarg_->accept(this);

  }

  /* check function body */ 
  if (program->listtopdef_) program->listtopdef_->accept(this);

}

void JLCTypeChecker::visitFnDef(FnDef *fn_def)
{
  /* Code For FnDef Goes Here */
  
  // if (fn_def->type_) fn_def->type_->accept(this);
  // visitIdent(fn_def->ident_);

  // update the current frame name, which mean we are in this function
  globalContext.currentFrameName = fn_def->ident_;
  
  // we move argument visiting to "visitProgram" function
  // if (fn_def->listarg_) fn_def->listarg_->accept(this);
  DEBUG_PRINT( "[" + checkerName +"]" + " visiting function body" + fn_def->ident_);
  if (fn_def->blk_) fn_def->blk_->accept(this);
}

void JLCTypeChecker::visitArgument(Argument *argument)
{
  /* Code For Argument Goes Here */
  if (argument->type_) argument->type_->accept(this);
  DEBUG_PRINT("\tArgument name: " + argument->ident_ + 
    "\tArgument type: " + to_string(temp_type));
  // check if the type is ok: case 072, void type
  if(temp_type == VOID){
    std::cerr << "ERROR: Argument " << argument->ident_ 
        << " in function:"<< globalContext.currentFrameName
        << " has void type" << std::endl;
    exit(1);
  }

  Frame& func = globalContext.getFrame(globalContext.currentFrameName);
  // check if the argument is already declared
  if(func.isExistArg(argument->ident_)){
    std::cerr << "ERROR: Argument " << argument->ident_ 
        << " in function:"<< globalContext.currentFrameName
        << " is already declared" << std::endl;
    exit(1);
  }
  // add the argument to the function
  func.addArg(argument->ident_, temp_type);
  visitIdent(argument->ident_);
}

void JLCTypeChecker::visitBlock(Block *block)
{
  /* Code For Block Goes Here */
  DEBUG_PRINT( "[" + checkerName +"]" + " visiting Block");
  // create a new block 
  auto & frame = globalContext.currentFrame();
  frame.newBlock();
  if (block->liststmt_) block->liststmt_->accept(this);
  // check if the function block has a return statement
  if(frame.blk->parent == nullptr &&  isReturnStmt == false && frame.returnType != VOID){
    std::cerr << "ERROR: function " << frame.name << " should have a return statement before the end of the function\n";
    exit(1);
  }
  // release the block
  frame.releaseBlock();

}

void JLCTypeChecker::visitDecl(Decl *decl)
{
  /* Code For Decl Goes Here */
  if (decl->type_) decl->type_->accept(this);
  DEBUG_PRINT( "[" + checkerName +"]" + "\tDeclaring variable: type(" 
    + to_string(temp_type) + ")");
  // cannot declare a variable with void type
  if(temp_type == VOID){
    std::cerr << "ERROR: cannot declare a variable with void type\n";
    exit(1);
  }
  auto temp_decl_type = temp_type;
  auto & frame = globalContext.currentFrame();
  for (auto & item : *(decl->listitem_)){
    temp_type = temp_decl_type; // !! this is important, as the type will pase to the next level
    item->accept(this);
    if(frame.blk->isExistVar(temp_ident)){
      // check if the variable is already declared in this block !notice: not in the whole function
      std::cerr << "ERROR: variable " << temp_ident << " is already declared.\n";
      exit(1);
    }    
    // Add the variable to the current block
    DEBUG_PRINT( "[" + checkerName +"]" + "\tAdding variable " + temp_ident + " to the block");
    frame.addVar(temp_ident, temp_decl_type);
  }


  
  if (decl->listitem_) decl->listitem_->accept(this);
}




void JLCTypeChecker::visitAss(Ass *ass)
{
  /* Code For Ass Goes Here */

  visitIdent(ass->ident_);
  // check if the variable is already declared in this context
  auto &frame = globalContext.currentFrame();
  if (!frame.isExistVar(ass->ident_)) {
    std::cerr << "ERROR: Variable " << ass->ident_ << " is not declared.\n";
    exit(1);
  }
  auto temp_type_2 = frame.getVarType(ass->ident_);

  if (ass->expr_) ass->expr_->accept(this);
  // check if the expr_ type is same as ass left-hand
  if(temp_type != temp_type_2){
    std::cerr << "ERROR: Type mismatch between expression and variable assignment."
    << " left-hand: "<< ass->ident_ << " type:" 
    << to_string(temp_type_2)
    << " right-hand: " << std::string(p.print(ass->expr_)) 
    << " type:" << to_string(temp_type) << '\n';
      exit(1);
  }
}


void JLCTypeChecker::visitArrayAss(ArrayAss *array_ass)
{
  /* Code For ArrayAss Goes Here */

  if (array_ass->expr_1) array_ass->expr_1->accept(this);

  auto temp_type_2 = temp_type;

  if (array_ass->expr_2) array_ass->expr_2->accept(this);
  if(temp_type != temp_type_2){
    std::cerr << "ERROR: Array ass type cant match.\n";
    exit(1);
  }
}


void JLCTypeChecker::visitIncr(Incr *incr)
{
  /* Code For Incr Goes Here */
  // check if the variable is already declared.
  auto& frame = globalContext.currentFrame();
  if (!frame.isExistVar(incr->ident_)) {
    std::cerr << "ERROR: Variable " << incr->ident_ << " is not declared.\n";
    exit(1);
  }
  // check var type is INT 
  if (frame.getVarType(incr->ident_) != INT){
    std::cerr << "ERROR: Variable " << incr->ident_ << " is not of type INT.\n";
    exit(1);
  } 

  visitIdent(incr->ident_);
}

void JLCTypeChecker::visitDecr(Decr *decr)
{
  /* Code For Decr Goes Here */
  auto& frame = globalContext.currentFrame();
  if (!frame.isExistVar(decr->ident_)) {
    std::cerr << "ERROR: Variable " << decr->ident_ << " in \"" 
    <<  std::string(p.print(decr))
    << "\" is not declared.\n";
    exit(1);
  }
  // check var type is INT 
  if (frame.getVarType(decr->ident_) != INT){
    std::cerr << "ERROR: Variable " << decr->ident_ << " in \"" <<  std::string(p.print(decr))
    << "\" is not of type INT.\n";
    exit(1);
  } 
  visitIdent(decr->ident_);

}

void JLCTypeChecker::visitRet(Ret *ret)
{
  /* Code For Ret Goes Here */

  if (ret->expr_) ret->expr_->accept(this);
  // check if the function return type is the same as the expression type
  auto & frame = globalContext.currentFrame();
  if(frame.returnType != temp_type){
    std::cerr << "ERROR: function " << frame.name << " should return a value with type:" 
    << to_string(frame.returnType) << ", but " << to_string(temp_type) << " is provided\n";
    exit(1);
  }
  isReturnStmt = true;
}

void JLCTypeChecker::visitVRet(VRet *v_ret)
{
  /* Code For VRet Goes Here */
  // check if the function return type is void
  auto & frame = globalContext.currentFrame();
  if(frame.returnType != VOID){
    std::cerr << "ERROR: function " << frame.name << " should return a value\n";
    exit(1);
  }
  isReturnStmt = true;
}

void JLCTypeChecker::visitCond(Cond *cond)
{
  /* Code For Cond Goes Here */

  if (cond->expr_) cond->expr_->accept(this);
  // check if the expression type is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(cond->expr_)) + " is not bool type\n";
    exit(1);
  }
  if (cond->stmt_) cond->stmt_->accept(this);
  isReturnStmt = false;
}

void JLCTypeChecker::visitCondElse(CondElse *cond_else)
{
  /* Code For CondElse Goes Here */

  if (cond_else->expr_) cond_else->expr_->accept(this);
  // check if the expression type is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(cond_else->expr_)) + " is not bool type\n";
    exit(1);
  }
  if (cond_else->stmt_1) cond_else->stmt_1->accept(this);
  auto local_return = isReturnStmt;
  isReturnStmt = false;
  if (cond_else->stmt_2) cond_else->stmt_2->accept(this);
  auto local_return_2 = isReturnStmt;
  isReturnStmt = local_return && local_return_2;
}

void JLCTypeChecker::visitWhile(While *while_)
{
  /* Code For While Goes Here */

  if (while_->expr_) while_->expr_->accept(this);
  // check if the expression type is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(while_->expr_)) + " is not bool type\n";
    exit(1);
  }
  if (while_->stmt_) while_->stmt_->accept(this);
  isReturnStmt = false;
}



void JLCTypeChecker::visitForBlk(ForBlk *for_blk)
{
  /* Code For ForBlk Goes Here */

  if (for_blk->type_) for_blk->type_->accept(this);
  if(temp_type == VOID){
    std::cerr << "ERROR: cannot declare a variable with void type\n";
    exit(1);
  }
  auto temp_decl_type = temp_type;
  auto & frame = globalContext.currentFrame();

  temp_type = temp_decl_type;
  if (for_blk->item_) for_blk->item_->accept(this);
  frame.addVar(temp_ident, temp_decl_type);
  
  if (for_blk->stmt_) for_blk->stmt_->accept(this);
  isReturnStmt = false;
}


void JLCTypeChecker::visitForLoop(ForLoop *for_loop)
{
  /* Code For ForLoop Goes Here */
  auto & frame = globalContext.currentFrame();
  frame.newBlock();
  if (for_loop->stmt_) for_loop->stmt_->accept(this);
  
  frame.releaseBlock();
}




void JLCTypeChecker::visitSExp(SExp *s_exp)
{
  /* Code For SExp Goes Here */
  temp_exp_type = "DEFAULT";
  if (s_exp->expr_) s_exp->expr_->accept(this);
  if (temp_exp_type.find("ELit") != std::string::npos){ 
    std::cerr << "ERROR: expression " + std::string(p.print(s_exp->expr_)) + " is invalid\n";
    exit(1);
  }
}

void JLCTypeChecker::visitNoInit(NoInit *no_init)
{
  /* Code For NoInit Goes Here */
  DEBUG_PRINT( "[" + checkerName +"]" + "\tNoInit");
  visitIdent(no_init->ident_);
  temp_ident = no_init->ident_;

}

void JLCTypeChecker::visitInit(Init *init)
{
  /* Code For Init Goes Here */
  DEBUG_PRINT( "[" + checkerName +"]" + "\tInit");
  visitIdent(init->ident_);
  temp_ident = init->ident_;
  auto temp_decl_type = temp_type; // !this type is passed from top level
  if (init->expr_) init->expr_->accept(this);
  // check if the init type is same as the variable type
  if (temp_type != temp_decl_type){
    std::cerr << "ERROR: Type mismatch between expression and variable assignment."
    << " left-hand: "<< init->ident_ << " type:" 
    << to_string(temp_decl_type)
    << " right-hand: " << std::string(p.print(init->expr_)) 
    << " type:" << to_string(temp_type) << "\n";
      exit(1);
  }
}


void JLCTypeChecker::visitInitElem(InitElem *init_elem)
{
  /* Code For InitElem Goes Here */

  visitIdent(init_elem->ident_);
  temp_ident = init_elem->ident_;
  auto temp_decl_type = temp_type;

  if (init_elem->expr_) init_elem->expr_->accept(this);
  if(temp_type!= INTARRAY && temp_type != DOUBARRAY && temp_type != BOOLARRAY ){
    std::cerr << "ERROR: Array Variable  is not declared.\n";
    exit(1);
  }
  if(temp_type == INTARRAY) temp_type = INT;
  if(temp_type == DOUBARRAY) temp_type = DOUB;
  if(temp_type == BOOLARRAY) temp_type = BOOL;

  if(temp_decl_type!=temp_type) {
     std::cerr << "ERROR: Type mismatch between expression and variable assignment."
    << " left-hand: "<< init_elem->ident_ << " type:" 
    << to_string(temp_decl_type)
    << " right-hand: " << std::string(p.print(init_elem->expr_)) 
    << " type:" << to_string(temp_type) << "\n";
      exit(1);
  }

}

void JLCTypeChecker::visitInt(Int *int_)
{
  /* Code For Int Goes Here */
  temp_type = INT;
}

void JLCTypeChecker::visitDoub(Doub *doub)
{
  /* Code For Doub Goes Here */
  temp_type = DOUB;
}

void JLCTypeChecker::visitBool(Bool *bool_)
{
  /* Code For Bool Goes Here */
  temp_type = BOOL;

}

void JLCTypeChecker::visitVoid(Void *void_)
{
  /* Code For Void Goes Here */
  temp_type = VOID;

}

void JLCTypeChecker::visitIntArray(IntArray *int_array)
{
  /* Code For IntArray Goes Here */
  temp_type = INTARRAY;

}

void JLCTypeChecker::visitDoubArray(DoubArray *doub_array)
{
  /* Code For DoubArray Goes Here */
  temp_type = DOUBARRAY;

}

void JLCTypeChecker::visitBoolArray(BoolArray *bool_array)
{
  /* Code For BoolArray Goes Here */
  temp_type = BOOLARRAY;

}

void JLCTypeChecker::visitFun(Fun *fun)
{
  /* Code For Fun Goes Here */

  if (fun->type_) fun->type_->accept(this);
  if (fun->listtype_) fun->listtype_->accept(this);

}

void JLCTypeChecker::visitEVar(EVar *e_var)
{
  /* Code For EVar Goes Here */
  // check if the variable is declared
  auto & frame = globalContext.currentFrame();
  if(!frame.isExistVar(e_var->ident_)){
    std::cerr << "ERROR: variable " << e_var->ident_ << " is not declared\n";
    exit(1);
  }
  temp_type = frame.getVarType(e_var->ident_);
  visitIdent(e_var->ident_);
}

void JLCTypeChecker::visitEArrayNew(EArrayNew *e_array_new)
{
  /* Code For EArrayNew Goes Here */


  if (e_array_new->expr_) e_array_new->expr_->accept(this);
  if(temp_type != INT){
    std::cerr << "ERROR: can just declare a array of [] int type\n";
    exit(1);
  }
  if (e_array_new->type_) e_array_new->type_->accept(this);
  if(temp_type == VOID){
    std::cerr << "ERROR: cannot declare a array variable with void type\n";
    exit(1);
  }
  if(temp_type == INT) temp_type = INTARRAY;
  if(temp_type == DOUB) temp_type = DOUBARRAY;
  if(temp_type == BOOL) temp_type = BOOLARRAY;
}


void JLCTypeChecker::visitEArrayLen(EArrayLen *e_array_len)
{
  /* Code For EArrayLen Goes Here */

  if (e_array_len->expr_1) e_array_len->expr_1->accept(this);
  auto temp_type_2 = temp_type;
  if(temp_type_2!= INTARRAY && temp_type_2 != DOUBARRAY && temp_type_2 != BOOLARRAY ){
    std::cerr << "ERROR: Array Variable  is not declared.\n";
    exit(1);
  }
  auto &frame = globalContext.currentFrame();
  frame.newBlock();
  if(!frame.isExistVar("length")){
    frame.addVar("length",UNDEFINED);
  }
  
  if (e_array_len->expr_2) e_array_len->expr_2->accept(this);
  frame.releaseBlock();
  temp_type = INT;

}



void JLCTypeChecker::visitEArray(EArray *e_array)
{
  /* Code For EArray Goes Here */

  if (e_array->expr_1) e_array->expr_1->accept(this);
  auto temp_type_2 = temp_type;
  if (e_array->expr_2) e_array->expr_2->accept(this);
  if(temp_type!=INT){
    std::cerr << "ERROR: type for operation [] can just be int\n";
    exit(1);
  }

  temp_type = temp_type_2;
  if(temp_type == INTARRAY) temp_type = INT;
  if(temp_type == DOUBARRAY) temp_type = DOUB;
  if(temp_type == BOOLARRAY) temp_type = BOOL;
 

}


void JLCTypeChecker::visitELitInt(ELitInt *e_lit_int)
{
  /* Code For ELitInt Goes Here */
  temp_exp_type = "ELitInt";
  visitInteger(e_lit_int->integer_);
  temp_type = INT;

}

void JLCTypeChecker::visitELitDoub(ELitDoub *e_lit_doub)
{
  /* Code For ELitDoub Goes Here */
  temp_exp_type = "ELitDoub";
  visitDouble(e_lit_doub->double_);
  temp_type = DOUB;

}

void JLCTypeChecker::visitELitTrue(ELitTrue *e_lit_true)
{
  /* Code For ELitTrue Goes Here */
  temp_exp_type = "ELitTrue";
  temp_type = BOOL;

}

void JLCTypeChecker::visitELitFalse(ELitFalse *e_lit_false)
{
  /* Code For ELitFalse Goes Here */
  temp_exp_type = "ELitFalse";
  temp_type = BOOL;
}

void JLCTypeChecker::visitEApp(EApp *e_app)
{
  /* Code For EApp Goes Here */
  DEBUG_PRINT( "[" + checkerName +"]" + " \tvisiting function call " + e_app->ident_);
  // check if the function is declared
  if(!globalContext.isExistFunction(e_app->ident_)){
    std::cerr << "ERROR: function " << e_app->ident_ << " is not declared\n";
    exit(1);
  }
  
  auto & frame = globalContext.getFrame(e_app->ident_);
  // check if the number of arguments is correct
  if(frame.args.size() != e_app->listexpr_->size()){
    std::cerr << "ERROR: function " << e_app->ident_ << " has " << frame.args.size() 
    << " arguments, but " << e_app->listexpr_->size() << " arguments are provided\n";
    exit(1);
  }

  // check if the type of arguments is correct
  auto i = e_app->listexpr_->begin();
  for(auto & arg : frame.args){
    (*i)->accept(this);
    if(temp_type != arg.second){
      std::cerr << "ERROR: function " << e_app->ident_ << " has " << arg.first << 
      " argument with type:" << to_string(arg.second) << ", but " << to_string(temp_type) << " argument is provided\n";
      exit(1);
    }
    i++;
  }
  temp_type = frame.returnType;

  // visitIdent(e_app->ident_);
  // if (e_app->listexpr_) e_app->listexpr_->accept(this);
  
  temp_exp_type = "EApp";
}



void JLCTypeChecker::visitEString(EString *e_string)
{
  /* Code For EString Goes Here */
  temp_exp_type = "ELitString";
  temp_type = STRING;
  visitString(e_string->string_);

}

void JLCTypeChecker::visitNeg(Neg *neg)
{
  /* Code For Neg Goes Here */

  if (neg->expr_) neg->expr_->accept(this);
  // type dont' change
  // temp_type = temp_type;
  if (temp_type == VOID){
    std::cerr << "ERROR: expression " + std::string(p.print(neg)) + " is void type\n";
    exit(1);
  }
  
}

void JLCTypeChecker::visitNot(Not *not_)
{
  /* Code For Not Goes Here */

  if (not_->expr_) not_->expr_->accept(this);
  if (temp_type == VOID){
    std::cerr << "ERROR: expression " + std::string(p.print(not_)) + " is void type\n";
    exit(1);
  }
}

void JLCTypeChecker::visitEMul(EMul *e_mul)
{
  /* Code For EMul Goes Here */

  if (e_mul->expr_1) e_mul->expr_1->accept(this);
  auto temp_type_1 = temp_type;
  if (e_mul->mulop_) e_mul->mulop_->accept(this);
  auto local_op = temp_op;
  if (e_mul->expr_2) e_mul->expr_2->accept(this);
  auto temp_type_2 = temp_type;
  // check if the type of the two expressions are the same
  if(temp_type_1 != temp_type_2){
    std::cerr << "ERROR: expression " + std::string(p.print(e_mul->expr_1)) + " type:"
    + to_string(temp_type_1) + " and " + std::string(p.print(e_mul->expr_2)) + " type:"
    + to_string(temp_type_2) + " have different types\n";
    exit(1);
  }
  // if op is MOD, the type should be int
  if(local_op == eMOD){
    if(temp_type != INT){
      std::cerr << "ERROR: expression " + std::string(p.print(e_mul->expr_1)) + " type:"
      + to_string(temp_type_1) + " and " + std::string(p.print(e_mul->expr_2)) + " type:"
      + to_string(temp_type_2) + " are not int type, Mod operation should be int type\n";
      exit(1);
    }
  }

}

void JLCTypeChecker::visitEAdd(EAdd *e_add)
{
  /* Code For EAdd Goes Here */

  if (e_add->expr_1) e_add->expr_1->accept(this);
  auto temp_type_1 = temp_type;
  if (e_add->addop_) e_add->addop_->accept(this);
  if (e_add->expr_2) e_add->expr_2->accept(this);
  auto temp_type_2 = temp_type;
  // check if the type of the two expressions are the same
  if(temp_type_1 != temp_type_2){
    std::cerr << "ERROR: expression " + std::string(p.print(e_add->expr_1)) + " type:"
    + to_string(temp_type_1) + " and " + std::string(p.print(e_add->expr_2)) + " type:"
    + to_string(temp_type_2) + " have different types\n";
    exit(1);
  }
}

void JLCTypeChecker::visitERel(ERel *e_rel)
{
  /* Code For ERel Goes Here */

  if (e_rel->expr_1) e_rel->expr_1->accept(this);
  auto temp_type_1 = temp_type;
  if (e_rel->relop_) e_rel->relop_->accept(this);
  auto local_op = temp_op;
  (void) local_op; // make the compiler happy
  if (e_rel->expr_2) e_rel->expr_2->accept(this);
  auto temp_type_2 = temp_type;
  // check if the type of the two expressions are the same
  if(temp_type_1 != temp_type_2){
    std::cerr << "ERROR: expression " + std::string(p.print(e_rel->expr_1)) + " type:"
    + to_string(temp_type_1) + " and " + std::string(p.print(e_rel->expr_2)) + " type:"
    + to_string(temp_type_2) + " have different types\n";
    exit(1);
  }
  temp_type = BOOL;
}

void JLCTypeChecker::visitEAnd(EAnd *e_and)
{
  /* Code For EAnd Goes Here */

  if (e_and->expr_1) e_and->expr_1->accept(this);
  // check if the type of the first expression is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(e_and->expr_1)) + " is not bool type\n";
    exit(1);
  }

  if (e_and->expr_2) e_and->expr_2->accept(this);
  // check if the type of the second expression is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(e_and->expr_2)) + " is not bool type\n";
    exit(1);
  }
  temp_type = BOOL;
}

void JLCTypeChecker::visitEOr(EOr *e_or)
{
  /* Code For EOr Goes Here */

  if (e_or->expr_1) e_or->expr_1->accept(this);
  // check if the type of the first expression is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(e_or->expr_1)) + " is not bool type\n";
    exit(1);
  }
  if (e_or->expr_2) e_or->expr_2->accept(this);
  // check if the type of the second expression is bool
  if(temp_type != BOOL){
    std::cerr << "ERROR: expression " + std::string(p.print(e_or->expr_2)) + " is not bool type\n";
    exit(1);
  }
  temp_type = BOOL;
}

void JLCTypeChecker::visitTimes(Times *times)
{
  /* Code For Times Goes Here */
  temp_op = eMUL;
}

void JLCTypeChecker::visitDiv(Div *div)
{
  /* Code For Div Goes Here */
  temp_op = eDIV;
}

void JLCTypeChecker::visitMod(Mod *mod)
{
  /* Code For Mod Goes Here */
  temp_op = eMOD;
}

void JLCTypeChecker::visitLTH(LTH *lth)
{
  /* Code For LTH Goes Here */
  temp_op = eLT;
}

void JLCTypeChecker::visitLE(LE *le)
{
  /* Code For LE Goes Here */
  temp_op = eLE;

}

void JLCTypeChecker::visitGTH(GTH *gth)
{
  /* Code For GTH Goes Here */
  temp_op = eGT;

}

void JLCTypeChecker::visitGE(GE *ge)
{
  /* Code For GE Goes Here */
  temp_op = eGE;
}

void JLCTypeChecker::visitEQU(EQU *equ)
{
  /* Code For EQU Goes Here */
  temp_op = eEQ;

}

void JLCTypeChecker::visitNE(NE *ne)
{
  /* Code For NE Goes Here */
  temp_op = eNE;
}

void JLCTypeChecker::visitListStmt(ListStmt *list_stmt)
{
  for (ListStmt::iterator i = list_stmt->begin() ; i != list_stmt->end() ; ++i)
  {
    DEBUG_PRINT( "[" + checkerName +"]" + " \tvisiting statement");
    isReturnStmt = false;
    (*i)->accept(this);
  }
}



