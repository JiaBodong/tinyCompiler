
Parse Successful!

[Abstract Syntax]
(Program [(FnDef [Int] "f" [(Argument [Int] "x"), (Argument [Int] "y")] [(Block [(Ret [(EAdd (EVar "x") [Plus] (EVar "y"))] )] )]), (FnDef [Void] "b" [(Argument [Int] "x")] [(Block [VRet] )]), (FnDef [Int] "main" [] [(Block [(Decl [Int] [(Init "a" [(ELitInt 2)])] ), (SExp [(EApp "f" [(EApp "f" [(EVar "a"), (ELitInt 1)] ), (EVar "a")] )] ), (SExp [(EApp "b" [(EVar "a")] )] ), (Ret [(ELitInt 0)] )] )])])

[Linearized Tree]
int f (int x, int y)
{
  return x + y;
}
void b (int x)
{
  return;
}
int main ()
{
  int a = 2;
  f (f (a, 1), a);
  b (a);
  return 0;
}


[DEBUG]:Add function declearation: declare void @printDouble(double)

[DEBUG]:Add function declearation: declare void @printInt(i32)

[DEBUG]:Add function declearation: declare void @printString(ptr)

[DEBUG]:Add function declearation: declare double @readDouble()

[DEBUG]:Add function declearation: declare i32 @readInt()

[DEBUG]:	Argument name: x	Argument type: int
[DEBUG]:	Argument name: y	Argument type: int
[DEBUG]:	Argument name: x	Argument type: int
[DEBUG]:Add function define: declare i32 @f(i32, i32)

[DEBUG]:[JLCLLVMGenerator] visiting Block
[DEBUG]:init args
[DEBUG]:go through the block
[DEBUG]:release block
[DEBUG]:Add function define: declare void @b(i32)

[DEBUG]:[JLCLLVMGenerator] visiting Block
[DEBUG]:init args
[DEBUG]:go through the block
[DEBUG]:visitVRet
[DEBUG]:release block
[DEBUG]:Add function define: declare i32 @main()

[DEBUG]:[JLCLLVMGenerator] visiting Block
[DEBUG]:init args
[DEBUG]:go through the block
[DEBUG]:release block
; ModuleID = 'JLC_llvm'
source_filename = "JLC_llvm"

declare void @printDouble(double)

declare void @printInt(i32)

declare void @printString(ptr)

declare double @readDouble()

declare i32 @readInt()

define i32 @f(i32 %x, i32 %y) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %x3 = load i32, ptr %x1, align 4
  %y4 = load i32, ptr %y2, align 4
  %add = add i32 %x3, %y4
  ret i32 %add
}

define void @b(i32 %x) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  ret void
}

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 2, ptr %a, align 4
  %a1 = load i32, ptr %a, align 4
  %f = call i32 @f(i32 %a1, i32 1)
  %a2 = load i32, ptr %a, align 4
  %f3 = call i32 @f(i32 %f, i32 %a2)
  %a4 = load i32, ptr %a, align 4
  call void @b(i32 %a4)
  ret i32 0
}
