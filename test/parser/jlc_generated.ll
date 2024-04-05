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
