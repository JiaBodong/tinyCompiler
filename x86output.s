extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 Str1 db "I'm here!", 0
section .text
global main
func:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  lea rdi, [Str1]
  call printString
  nop
  leave
  ret
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], 0
  call func
  mov eax, 0
  leave
  ret
