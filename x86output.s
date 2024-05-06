extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 FP1 dd 0.000000
 Str1 db 'AMD,Yes!', 0
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], 0
  movss xmm0, dword [FP1]
  movss dword [rbp-8], xmm0
  mov eax, dword [rbp-4]
  mov edi, eax
  call printInt
  movss xmm0, dword [rbp-8]
  cvtss2sd xmm0, xmm0
  call printDouble
  lea rdi, [Str1]
  call printString
  mov eax, 0
  leave
  ret
