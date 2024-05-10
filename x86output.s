extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 epsilon dd 0.0000001
 FP1 dd 9.300000
 FP2 dd 5.100000
 Str1 db "true", 0
 Str2 db "false", 0
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 32
  mov dword [rbp-4], 56
  mov dword [rbp-8], -23
  mov eax, dword [rbp-4]
  mov ebx, dword [rbp-8]
  add eax, ebx
  mov edi, eax
  call printInt
  mov eax, dword [rbp-4]
  mov ebx, dword [rbp-8]
  sub eax, ebx
  mov edi, eax
  call printInt
  mov eax, dword [rbp-4]
  imul eax, dword [rbp-8]
  mov edi, eax
  call printInt
  mov edi, 22
  call printInt
  mov edi, 0
  call printInt
  movss xmm0, dword [FP1]
  movss dword [rbp-12], xmm0
  movss xmm0, dword [FP2]
  movss dword [rbp-16], xmm0
  movss xmm0, dword [rbp-12]
  movss xmm1, dword [rbp-16]
  addss xmm0, xmm1
  movss xmm1, dword [rbp-12]
  movss xmm10, dword [rbp-16]
  subss xmm1, xmm10
  ucomiss xmm1, xmm1
  and eax, 1
  movzx eax, al
  mov edi, eax
  call printBool
  movss xmm1, dword [rbp-12]
  movss xmm10, dword [rbp-16]
  divss xmm1, xmm10
  movss xmm10, dword [rbp-12]
  movss xmm11, dword [rbp-16]
  mulss xmm10, xmm11
  ucomiss xmm10, xmm10
  and eax, 1
  movzx eax, al
  mov edi, eax
  call printBool
  mov eax, 0
  leave
  ret
printBool:
  push rbp
  mov rbp, rsp
  sub rsp, 16

  movzx eax, byte [rbp-4]
.LB1:
  lea rdi, [Str1]
  call printString
  nop
  leave
  ret
  jmp .LB3
.LB2:
  lea rdi, [Str2]
  call printString
  nop
  leave
  ret
.LB3:
.LB0:
  leave
  ret
