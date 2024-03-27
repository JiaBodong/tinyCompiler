/* File generated by the BNF Converter (bnfc 2.9.4). */

/*** Visitor Traversal Skeleton. ***/
/* This traverses the abstract syntax tree.
   To use, copy Skeleton.h and Skeleton.c to
   new files. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Skeleton.h"
#include "Absyn.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* TODO add if hasValue check*/
struct KeyValuePair {
    char* key;
    char* value;
    struct KeyValuePair* next;
};

struct KeyValuePair* globalMap = NULL;

void addToMap(Ident key1, char* key2, char* value);
char* getValue(Ident key1, char* key2);

/* add kv to table */
void addToMap(Ident key1, char* key2, char* value) {
    // Concatenate key1 and key2 with a delimiter
    char* combinedKey = malloc(strlen(key1) + strlen(key2) + 2); // +2 for delimiter and null terminator
    if (combinedKey == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(combinedKey, key1);
    strcat(combinedKey, "_"); // Use underscore as delimiter
    strcat(combinedKey, key2);

    // Add key-value pair to the map
    struct KeyValuePair* newNode = malloc(sizeof(struct KeyValuePair));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->key = combinedKey;
    newNode->value = value;
    newNode->next = globalMap;
    globalMap = newNode;
}

/* get value from table */
char* getValue(Ident key1, char* key2) {
    // Concatenate key1 and key2 with a delimiter
    char* combinedKey = malloc(strlen(key1) + strlen(key2) + 2); // +2 for delimiter and null terminator
    if (combinedKey == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(combinedKey, key1);
    strcat(combinedKey, "_"); // Use underscore as delimiter
    strcat(combinedKey, key2);

    // Search for the combined key in the map
    struct KeyValuePair* current = globalMap;
    while (current != NULL) {
        if (strcmp(current->key, combinedKey) == 0) {
            free(combinedKey); // Free memory allocated for combinedKey
            return current->value;
        }
        current = current->next;
    }
    free(combinedKey); // Free memory allocated for combinedKey
    return NULL;
}


 /*func kv map */
/* Structure to represent a function entry in the key-value map */
struct FunctionEntry {
    Ident name;            // func name
    char* returnType;     // Return type
    int numParameters;    // Number of parameters
    char** parameterTypes;  // Array to store parameter types
    struct FunctionEntry* next;  // Pointer to the next function entry
};

struct FunctionEntry* functionMap = NULL;

/* Function to add a function entry to the map */
void addFunctionToMap(Ident name, char* returnType, int numParameters, char** parameterTypes) {
    struct FunctionEntry* newFunction = malloc(sizeof(struct FunctionEntry));
    newFunction->name = strdup(name);
    newFunction->returnType = strdup(returnType);
    newFunction->numParameters = numParameters;

    // Allocate memory for parameter types and copy them
    newFunction->parameterTypes = malloc(numParameters * sizeof(char*));
    for (int i = 0; i < numParameters; ++i) {
        newFunction->parameterTypes[i] = strdup(parameterTypes[i]);
    }

    newFunction->next = functionMap;
    functionMap = newFunction;
}

/* Function to retrieve the function entry from the map */
struct FunctionEntry* getFunctionFromMap(Ident name) {
    struct FunctionEntry* current = functionMap;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

 /*func kv map */


 



char* TypeTransferExpr(enum  Expr_ { is_EVar, is_ELitInt, is_ELitDoub, is_ELitTrue, is_ELitFalse, is_EApp, is_EString, is_Neg, is_Not, is_EMul, is_EAdd, is_ERel, is_EAnd, is_EOr } kind){
  switch(kind)
  {
  case is_ELitInt:
    return "Int";
  case is_ELitDoub:
    return "Doub";
  case is_EApp:
    return "EApp";
  }
}

char* TypeTransferType(enum  Type_ { is_Int, is_Doub, is_Bool, is_Void, is_Fun } kind){
  switch(kind)
  {
  case is_Int:
    return "Int";
  case is_Doub:
    return "Doub";
  case is_Void:
    return "Void";
  }
}


void visitProg(Prog p)
{
  switch(p->kind)
  {
  case is_Program:
    /* Code for Program Goes Here */
    visitListTopDef(p->u.program_.listtopdef_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Prog!\n");
    exit(1);
  }
}

void visitTopDef(TopDef p)
{ 

  char* para[10]={NULL};
  int para_num=0;
  switch(p->kind)
  {
  case is_FnDef:
    
    visitType(p->u.fndef_.type_);
    visitIdent(p->u.fndef_.ident_);
    char* func_name = p->u.fndef_.ident_;

    visitListArg(p->u.fndef_.listarg_,func_name,&para_num,para);

    
    char* func_returntype = TypeTransferType(p->u.fndef_.type_->kind);

    /*record the values above into the function map*/
    addFunctionToMap(func_name,func_returntype,para_num,para);
    
    bool hasReturn = false;
    char* returnType =func_returntype;  /*get the type of local func */
    if((strcmp(returnType,"Void")==0)) hasReturn = true;

    visitBlk(p->u.fndef_.blk_,&hasReturn, returnType ,func_name );/* function return check in BLK */

    if(hasReturn == false) {
      fprintf(stderr, "Error: function no right return \n");
      exit(1);
    }
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing TopDef!\n");
    exit(1);
  }
}

void visitListTopDef(ListTopDef listtopdef)
{
  while(listtopdef  != 0)
  {
    
    /* Code For ListTopDef Goes Here */
    visitTopDef(listtopdef->topdef_);
    listtopdef = listtopdef->listtopdef_;
  }
}

void visitArg(Arg p, char* func_name)
{
  switch(p->kind)
  {
  case is_Argument:
    /* Code for Argument Goes Here */
    visitType(p->u.argument_.type_);
    visitIdent(p->u.argument_.ident_);
    addToMap(p->u.argument_.ident_,func_name,TypeTransferType(p->u.argument_.type_->kind));

    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Arg!\n");
    exit(1);
  }
}

void visitListArg(ListArg listarg,char* func_name,int* para_num, char** para)
{
  while(listarg  != 0)/* record argement number and type here*/
  { 
    
    visitArg(listarg->arg_,func_name);
    para[(*para_num)] = TypeTransferType(listarg->arg_->u.argument_.type_->kind);
    *para_num++;

    listarg = listarg->listarg_;
    /* here record the arg's type and ident */
  }
}

void visitBlk(Blk p, bool* hasReturn, char* returnType, char* func_name)
{
  switch(p->kind)
  {
  case is_Block:
    /* Code for Block Goes Here */
    visitListStmt(p->u.block_.liststmt_, hasReturn, returnType, func_name);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Blk!\n");
    exit(1);
  }
}

void visitListStmt(ListStmt liststmt, bool* hasReturn, char* returnType, char* func_name)
{
  while(liststmt  != 0)
  {
    /* Code For ListStmt Goes Here */
    visitStmt(liststmt->stmt_, hasReturn, returnType, func_name);
    liststmt = liststmt->liststmt_;
  }
}

void visitStmt(Stmt p, bool* hasReturn, char* returnType, char* func_name)
{
    /* for is_Cond */
  bool condReturn = false;
  char* condReturnType=malloc(10*sizeof(char));

    /* for is_Condelse */
  bool condelseReturn1 = false;
  char* condelseReturnType1=malloc(10*sizeof(char));
  bool condelseReturn2 = false;
  char* condelseReturnType2=malloc(10*sizeof(char));


  switch(p->kind)
  {
  case is_Empty:
    /* Code for Empty Goes Here */
    break;
  case is_BStmt:
    /* Code for BStmt Goes Here */
    visitBlk(p->u.bstmt_.blk_,hasReturn,returnType,func_name);
    break;
  case is_Decl:
    /* Code for Decl Goes Here */
    visitType(p->u.decl_.type_);
    visitListItem(p->u.decl_.listitem_,func_name);

    if(p->u.decl_.listitem_->item_->kind == is_NoInit){
      addToMap(p->u.decl_.listitem_->item_->u.noinit_.ident_, func_name,TypeTransferType(p->u.decl_.type_->kind));
    } else if(p->u.decl_.listitem_->item_->kind == is_Init){
      addToMap(p->u.decl_.listitem_->item_->u.init_.ident_, func_name,TypeTransferType(p->u.decl_.type_->kind));
    }
      
    break;
  case is_Ass:
    /* Code for Ass Goes Here */
    visitIdent(p->u.ass_.ident_);

    if(!getValue(p->u.ass_.ident_,func_name)){
      fprintf(stderr, "Error: not declared, cant ass!\n");
      exit(1);
    }
    
    visitExpr(p->u.ass_.expr_,func_name);


    if(p->u.ass_.expr_->kind==is_ELitInt || p->u.ass_.expr_->kind==is_ELitDoub){
      if(strcmp(getValue(p->u.ass_.ident_,func_name),TypeTransferExpr(p->u.ass_.expr_->kind))==0) break;
      else {
        fprintf(stderr, "Error: type fault, cant ass\n");
        exit(1);
      }
    } else if(p->u.ass_.expr_->kind == is_EVar){
      if(strcmp(getValue(p->u.ass_.ident_,func_name),TypeTransferType(p->u.ass_.expr_->kind))==0) break;
      else {
        fprintf(stderr, "Error: type fault, cant ass\n");
        exit(1);
      }
    }
  case is_Incr:
    /* Code for Incr Goes Here */
    visitIdent(p->u.incr_.ident_);
    break;
  case is_Decr:
    /* Code for Decr Goes Here */
    visitIdent(p->u.decr_.ident_);
    break;
  case is_Ret:
    /* Code for Ret Goes Here */
    visitExpr(p->u.ret_.expr_,func_name);

    if(strcmp(returnType,"Void")==0){
        fprintf(stderr, "Error: void dont return var \n");
        exit(1);
    }
    *hasReturn = true;
  
    if(p->u.ret_.expr_->kind == is_EVar){
       /* return variable not decled */
      if(!getValue(p->u.ret_.expr_->u.evar_.ident_,func_name)){
        fprintf(stderr, "Error: no decled var\n");
        exit(1);
      }
      if(strcmp(returnType,"Int")==0||strcmp(returnType,"Doub")==0){
        if(strcmp(getValue(p->u.ret_.expr_->u.evar_.ident_,func_name),returnType)!=0){
          fprintf(stderr, "Error: error return type\n");
          exit(1);
        }else{
          break;
        }
      }
    } 
    else if(p->u.ret_.expr_->kind == is_EApp){
      ;
    }
    else if(p->u.ret_.expr_->kind == is_EMul ||p->u.ret_.expr_->kind == is_EAdd){  /* process alu in the visitExpr()*/
      break;
    }
    else {
      if(strcmp(returnType,"Int")==0||strcmp(returnType,"Doub")==0){
        printf("%s\n",returnType);
        if(strcmp(TypeTransferExpr(p->u.ret_.expr_->kind),returnType)!=0){
          fprintf(stderr, "Error: error return type\n");
          exit(1);
        }else{
          break;
        }
      }
      /*
      strcpy(returnType, TypeTransferExpr(p->u.ret_.expr_->kind));
      printf("%s\n",returnType);*/
    }
    
    break;
  case is_VRet:
    /* Code for VRet Goes Here */
    if(strcmp(returnType,"Void")==0){
      break;
    } else{
      fprintf(stderr, "Error: just void func can return blank\n");
      exit(1);
    }

    break;
  case is_Cond:
    /* if  path return check */

    visitExpr(p->u.cond_.expr_,func_name);
    visitStmt(p->u.cond_.stmt_, &condReturn, returnType, func_name);

    if(condReturn == false){
      if(strcmp(returnType,"Void")==0){
        *hasReturn = true;
      }
      else{
        fprintf(stderr, "Error: if path dont return!\n");
        exit(1);
      }

    } else{

      *hasReturn = true;
      break;
    
    }

    break;
  case is_CondElse:
    /* if-else path return check*/

    visitExpr(p->u.condelse_.expr_,func_name);
    visitStmt(p->u.condelse_.stmt_1,&condelseReturn1,returnType,func_name);
    visitStmt(p->u.condelse_.stmt_2,&condelseReturn2,returnType,func_name);

    printf("%s\n",returnType);
    printf("%s\n",returnType);
    if(condelseReturn1 ==true && condelseReturn2 == true){

      *hasReturn = true;
      break;

    } else {
      if(strcmp(returnType,"Void")==0){
        *hasReturn = true;
        break;
      } else {
        fprintf(stderr, "Error: if-else path dont return!\n");
        exit(1);
      }
      
    }


    break;
  case is_While:
    /* TODO
    visitExpr(p->u.while_.expr_);
    visitStmt(p->u.while_.stmt_);
    */
    break;
  case is_SExp:
    /* Code for SExp Goes Here */
    visitExpr(p->u.sexp_.expr_,func_name);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Stmt!\n");
    exit(1);
  }
}

void visitItem(Item p, char* func_name)
{
  switch(p->kind)
  {
  case is_NoInit:
    /* Code for NoInit Goes Here */
    visitIdent(p->u.noinit_.ident_);
    break;
  case is_Init:
    /* Code for Init Goes Here */
    visitIdent(p->u.init_.ident_);
    visitExpr(p->u.init_.expr_,func_name);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Item!\n");
    exit(1);
  }
}

void visitListItem(ListItem listitem, char* func_name)
{
  while(listitem  != 0)
  {
    /* Code For ListItem Goes Here */
    visitItem(listitem->item_,func_name);
    listitem = listitem->listitem_;
  }
}

void visitType(Type p)
{
  switch(p->kind)
  {
  case is_Int:
    /* Code for Int Goes Here */
    break;
  case is_Doub:
    /* Code for Doub Goes Here */
    break;
  case is_Bool:
    /* Code for Bool Goes Here */
    break;
  case is_Void:
    /* Code for Void Goes Here */
    break;
  case is_Fun:
    /* Code for Fun Goes Here */
    visitType(p->u.fun_.type_);
    visitListType(p->u.fun_.listtype_);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Type!\n");
    exit(1);
  }
}

void visitListType(ListType listtype)
{
  while(listtype  != 0)
  {
    /* Code For ListType Goes Here */
    visitType(listtype->type_);
    listtype = listtype->listtype_;
  }
}

void visitExpr(Expr p, char* func_name)
{

  /*for isEApp*/
  char* localPara[10];
  int localParaNum;
  int isEqual = 1;
 /*for isEApp*/

  switch(p->kind)
  {
  case is_EVar:
    /* Code for EVar Goes Here */
    visitIdent(p->u.evar_.ident_);

    if(!getValue(p->u.evar_.ident_,func_name))
    {
      fprintf(stderr, "Error: not found value\n");
      exit(1);
    }
    break;
  case is_ELitInt:
    /* Code for ELitInt Goes Here */
    visitInteger(p->u.elitint_.integer_);
    break;
  case is_ELitDoub:
    /* Code for ELitDoub Goes Here */
    visitDouble(p->u.elitdoub_.double_);
    break;
  case is_ELitTrue:
    /* Code for ELitTrue Goes Here */
    break;
  case is_ELitFalse:
    /* Code for ELitFalse Goes Here */
    break;
  case is_EApp:
   
    visitIdent(p->u.eapp_.ident_);

     /* function decled check */
    if(!getFunctionFromMap(p->u.eapp_.ident_)){
      fprintf(stderr, "Error: called func not declcared\n");
      exit(1);
    }
    char* local_func_name = p->u.eapp_.ident_;

    visitListExpr(p->u.eapp_.listexpr_,local_func_name,&localParaNum,localPara);

    /* function vars compared */
    struct FunctionEntry* funcEntry = getFunctionFromMap(local_func_name);
    if(funcEntry->numParameters!=localParaNum){
      fprintf(stderr, "Error: called func para number dont match\n");
      exit(1);
    }

    for(int i=0; i< localParaNum; i++){
      if(strcmp(localPara[i],funcEntry->parameterTypes[i])!=0){
        isEqual = 0;
        break;
      }
    }

    if(isEqual==0){
      fprintf(stderr, "Error: called func para types dont match\n");
      exit(1);
    }

    break;
  case is_EString:
    /* Code for EString Goes Here */
    visitString(p->u.estring_.string_);
    break;
  case is_Neg:
    /* Code for Neg Goes Here */
    visitExpr(p->u.neg_.expr_,func_name);
    break;
  case is_Not:
    /* Code for Not Goes Here */
    visitExpr(p->u.not_.expr_,func_name);
    break;
  case is_EMul:
    /* Code for EMul Goes Here */
    
    visitExpr(p->u.emul_.expr_1,func_name);
    visitMulOp(p->u.emul_.mulop_);
    visitExpr(p->u.emul_.expr_2,func_name);

    struct FunctionEntry* localFuncEntry = getFunctionFromMap(func_name);
    char* LType = localFuncEntry->returnType;
    if(p->u.emul_.expr_1->kind == is_EVar && p->u.emul_.expr_2->kind == is_EVar )
    {
        if(strcmp(getValue(p->u.emul_.expr_1->u.evar_.ident_,func_name) ,getValue(p->u.emul_.expr_2->u.evar_.ident_,func_name))==0 && strcmp(getValue(p->u.emul_.expr_1->u.evar_.ident_,func_name) ,LType)==0) break;
        else {
          fprintf(stderr, "Error: ops type cant match or dont decl var\n");
          exit(1);
        }
    }
    else if(p->u.emul_.expr_1->kind == is_EVar || p->u.emul_.expr_2->kind == is_EVar)
    {
        if(p->u.emul_.expr_1->kind == is_EVar){
            if(strcmp(getValue(p->u.emul_.expr_1->u.evar_.ident_,func_name) , TypeTransferExpr(p->u.emul_.expr_2->kind))==0&& strcmp(getValue(p->u.emul_.expr_1->u.evar_.ident_,func_name) ,LType)==0) break;
            else {
              fprintf(stderr, "Error: ops type cant match or dont decl var\n");
              exit(1);
            }
        }
        else{
            if(strcmp(getValue(p->u.emul_.expr_2->u.evar_.ident_,func_name) , TypeTransferExpr(p->u.emul_.expr_1->kind))==0 && strcmp(getValue(p->u.emul_.expr_2->u.evar_.ident_,func_name) ,LType)==0) break;
            else {
              fprintf(stderr, "Error: ops type cant match or dont decl var\n");
              exit(1);
            }
        }     
    }
    else{
        if(strcmp(TypeTransferExpr(p->u.emul_.expr_2->kind), TypeTransferExpr(p->u.emul_.expr_1->kind))==0&&strcmp(TypeTransferExpr(p->u.emul_.expr_1->kind) ,LType)==0) break;
        else {
          fprintf(stderr, "Error: ops type cant match\n");
          exit(1);
        }
    }

  
  case is_EAdd:
    /* Code for EAdd Goes Here */
    visitExpr(p->u.eadd_.expr_1,func_name);
    visitAddOp(p->u.eadd_.addop_);
    visitExpr(p->u.eadd_.expr_2,func_name);
    break;
  case is_ERel:
    /* Code for ERel Goes Here */
    visitExpr(p->u.erel_.expr_1,func_name);
    visitRelOp(p->u.erel_.relop_);
    visitExpr(p->u.erel_.expr_2,func_name);
    break;
  case is_EAnd:
    /* Code for EAnd Goes Here */
    visitExpr(p->u.eand_.expr_1,func_name);
    visitExpr(p->u.eand_.expr_2,func_name);
    break;
  case is_EOr:
    /* Code for EOr Goes Here */
    visitExpr(p->u.eor_.expr_1,func_name);
    visitExpr(p->u.eor_.expr_2,func_name);
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing Expr!\n");
    exit(1);
  }
}

void visitListExpr(ListExpr listexpr, char* func_name, int* localParaNum, char** localPara)
{
  while(listexpr  != 0)
  {
    /* Code For ListExpr Goes Here */
    visitExpr(listexpr->expr_,func_name);

    switch(listexpr->expr_->kind)
    {
    case is_EVar:
      localPara[(*localParaNum)] = getValue(listexpr->expr_->u.evar_.ident_,func_name);
      
    case is_ELitInt:
      localPara[(*localParaNum)] = TypeTransferExpr(listexpr->expr_->kind);

    case is_ELitDoub:
      localPara[(*localParaNum)] = TypeTransferExpr(listexpr->expr_->kind);

    /*todo add all cases*/
    default:
      fprintf(stderr, "Error: bad kind field when printing Expr!\n");
      exit(1);
    }

    
    *localParaNum++;
    listexpr = listexpr->listexpr_;
  }
}

void visitAddOp(AddOp p)
{
  switch(p->kind)
  {
  case is_Plus:
    /* Code for Plus Goes Here */
    break;
  case is_Minus:
    /* Code for Minus Goes Here */
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing AddOp!\n");
    exit(1);
  }
}

void visitMulOp(MulOp p)
{
  switch(p->kind)
  {
  case is_Times:
    /* Code for Times Goes Here */
    break;
  case is_Div:
    /* Code for Div Goes Here */
    break;
  case is_Mod:
    /* Code for Mod Goes Here */
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing MulOp!\n");
    exit(1);
  }
}

void visitRelOp(RelOp p)
{
  switch(p->kind)
  {
  case is_LTH:
    /* Code for LTH Goes Here */
    break;
  case is_LE:
    /* Code for LE Goes Here */
    break;
  case is_GTH:
    /* Code for GTH Goes Here */
    break;
  case is_GE:
    /* Code for GE Goes Here */
    break;
  case is_EQU:
    /* Code for EQU Goes Here */
    break;
  case is_NE:
    /* Code for NE Goes Here */
    break;

  default:
    fprintf(stderr, "Error: bad kind field when printing RelOp!\n");
    exit(1);
  }
}

 /* these are the smallest units of the program */
void visitIdent(Ident i)
{
   /* record the status of i, decl? if decl, init or noinit? if init , what is the value? what's the type? */
  /* Code for Ident Goes Here */
}
void visitInteger(Integer i)
{
  fprintf(stderr, "visit integer\n");
  return;
  /* Code for Integer Goes Here */
}
void visitDouble(Double d)
{
  fprintf(stderr, "visit double\n");
  return;
  /* Code for Double Goes Here */
}
void visitChar(Char c)
{
  /* Code for Char Goes Here */
}
void visitString(String s)
{
  /* Code for String Goes Here */
}

