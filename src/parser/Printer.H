/* File generated by the BNF Converter (bnfc 2.9.4). */

#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void render(const char *s);
  void indent(void);
  void backup(void);
  void onEmptyLine(void);
  void removeTrailingSpaces(void);
  void removeTrailingWhitespace(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char *print(Visitable *v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitFnDef(FnDef *p);
  void visitListTopDef(ListTopDef *p);
  void iterListTopDef(ListTopDef::const_iterator i, ListTopDef::const_iterator j);
  void visitArg(Arg *p); /* abstract class */
  void visitArgument(Argument *p);
  void visitListArg(ListArg *p);
  void iterListArg(ListArg::const_iterator i, ListArg::const_iterator j);
  void visitBlk(Blk *p); /* abstract class */
  void visitBlock(Block *p);
  void visitListStmt(ListStmt *p);
  void iterListStmt(ListStmt::const_iterator i, ListStmt::const_iterator j);
  void visitStmt(Stmt *p); /* abstract class */
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitAss(Ass *p);
  void visitArrayAss(ArrayAss *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitForBlk(ForBlk *p);
  void visitForLoop(ForLoop *p);
  void visitSExp(SExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitInitElem(InitElem *p);
  void visitListItem(ListItem *p);
  void iterListItem(ListItem::const_iterator i, ListItem::const_iterator j);
  void visitType(Type *p); /* abstract class */
  void visitInt(Int *p);
  void visitDoub(Doub *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitIntArray(IntArray *p);
  void visitDoubArray(DoubArray *p);
  void visitBoolArray(BoolArray *p);
  void visitFun(Fun *p);
  void visitListType(ListType *p);
  void iterListType(ListType::const_iterator i, ListType::const_iterator j);
  void visitExpr(Expr *p); /* abstract class */
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitDoub(ELitDoub *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitEArrayNew(EArrayNew *p);
  void visitEArrayLen(EArrayLen *p);
  void visitEArray(EArray *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr *p);
  void iterListExpr(ListExpr::const_iterator i, ListExpr::const_iterator j);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  char *buf_;
  size_t cur_, buf_size;

  void inline bufAppend(const char *s)
  {
    size_t end = cur_ + strlen(s);
    if (end >= buf_size) {
      do buf_size *= 2; /* Double the buffer size */
      while (end >= buf_size);
      resizeBuffer();
    }
    strcpy(&buf_[cur_], s);
    cur_ = end;
  }

  void inline bufAppend(const char c)
  {
    if (cur_ + 1 >= buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    buf_[++cur_] = 0;
  }

  void inline bufAppend(String str)
  {
    const char *s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    if (buf_) delete[] buf_;
    buf_size = BUFFER_INITIAL;
    buf_ = new char[buf_size];
    memset(buf_, 0, buf_size);
    cur_ = 0;
  }

  void inline resizeBuffer(void)
  {
    char *temp = new char[buf_size];
    if (buf_)
    {
      strcpy(temp, buf_);
      delete[] buf_;
    }
    buf_ = temp;
  }
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char *show(Visitable *v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitTopDef(TopDef *p); /* abstract class */
  void visitFnDef(FnDef *p);
  void visitListTopDef(ListTopDef *p);
  void iterListTopDef(ListTopDef::const_iterator i, ListTopDef::const_iterator j);
  void visitArg(Arg *p); /* abstract class */
  void visitArgument(Argument *p);
  void visitListArg(ListArg *p);
  void iterListArg(ListArg::const_iterator i, ListArg::const_iterator j);
  void visitBlk(Blk *p); /* abstract class */
  void visitBlock(Block *p);
  void visitListStmt(ListStmt *p);
  void iterListStmt(ListStmt::const_iterator i, ListStmt::const_iterator j);
  void visitStmt(Stmt *p); /* abstract class */
  void visitEmpty(Empty *p);
  void visitBStmt(BStmt *p);
  void visitDecl(Decl *p);
  void visitAss(Ass *p);
  void visitArrayAss(ArrayAss *p);
  void visitIncr(Incr *p);
  void visitDecr(Decr *p);
  void visitRet(Ret *p);
  void visitVRet(VRet *p);
  void visitCond(Cond *p);
  void visitCondElse(CondElse *p);
  void visitWhile(While *p);
  void visitForBlk(ForBlk *p);
  void visitForLoop(ForLoop *p);
  void visitSExp(SExp *p);
  void visitItem(Item *p); /* abstract class */
  void visitNoInit(NoInit *p);
  void visitInit(Init *p);
  void visitInitElem(InitElem *p);
  void visitListItem(ListItem *p);
  void iterListItem(ListItem::const_iterator i, ListItem::const_iterator j);
  void visitType(Type *p); /* abstract class */
  void visitInt(Int *p);
  void visitDoub(Doub *p);
  void visitBool(Bool *p);
  void visitVoid(Void *p);
  void visitIntArray(IntArray *p);
  void visitDoubArray(DoubArray *p);
  void visitBoolArray(BoolArray *p);
  void visitFun(Fun *p);
  void visitListType(ListType *p);
  void iterListType(ListType::const_iterator i, ListType::const_iterator j);
  void visitExpr(Expr *p); /* abstract class */
  void visitEVar(EVar *p);
  void visitELitInt(ELitInt *p);
  void visitELitDoub(ELitDoub *p);
  void visitELitTrue(ELitTrue *p);
  void visitELitFalse(ELitFalse *p);
  void visitEApp(EApp *p);
  void visitEString(EString *p);
  void visitEArrayNew(EArrayNew *p);
  void visitEArrayLen(EArrayLen *p);
  void visitEArray(EArray *p);
  void visitNeg(Neg *p);
  void visitNot(Not *p);
  void visitEMul(EMul *p);
  void visitEAdd(EAdd *p);
  void visitERel(ERel *p);
  void visitEAnd(EAnd *p);
  void visitEOr(EOr *p);
  void visitListExpr(ListExpr *p);
  void iterListExpr(ListExpr::const_iterator i, ListExpr::const_iterator j);
  void visitAddOp(AddOp *p); /* abstract class */
  void visitPlus(Plus *p);
  void visitMinus(Minus *p);
  void visitMulOp(MulOp *p); /* abstract class */
  void visitTimes(Times *p);
  void visitDiv(Div *p);
  void visitMod(Mod *p);
  void visitRelOp(RelOp *p); /* abstract class */
  void visitLTH(LTH *p);
  void visitLE(LE *p);
  void visitGTH(GTH *p);
  void visitGE(GE *p);
  void visitEQU(EQU *p);
  void visitNE(NE *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  char *buf_;
  size_t cur_, buf_size;

  void inline bufAppend(const char *s)
  {
    size_t end = cur_ + strlen(s);
    if (end >= buf_size) {
      do buf_size *= 2; /* Double the buffer size */
      while (end >= buf_size);
      resizeBuffer();
    }
    strcpy(&buf_[cur_], s);
    cur_ = end;
  }

  void inline bufAppend(const char c)
  {
    if (cur_ + 1 >= buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    buf_[++cur_] = 0;
  }

  void inline bufAppend(String str)
  {
    const char *s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    if (buf_) delete[] buf_;
    buf_size = BUFFER_INITIAL;
    buf_ = new char[buf_size];
    memset(buf_, 0, buf_size);
    cur_ = 0;
  }

  void inline resizeBuffer(void)
  {
    char *temp = new char[buf_size];
    if (buf_)
    {
      strcpy(temp, buf_);
      delete[] buf_;
    }
    buf_ = temp;
  }
};




#endif

