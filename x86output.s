extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 FP1 dd 0.000000
 FP2 dd 0.001400
 FP3 dd 0.000400
 FP4 dd 0.001800
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 32
  movss xmm0, dword [FP1]
  movss dword [rbp-4], xmm0
  movss xmm0, dword [FP1]
  movss dword [rbp-8], xmm0
  movss xmm0, dword [FP2]
  movss dword [rbp-4], xmm0
  movss xmm0, dword [FP3]
  movss dword [rbp-8], xmm0
  movss xmm0, dword [rbp-4]
  movss xmm1, dword [rbp-8]
  addss xmm0, xmm1
  movss xmm1, dword [FP4]
  ucomiss xmm0, xmm1
  jne .LB2
.LB1:
  mov edi, 99
  call printInt
.LB2:
  mov dword [rbp-12], 0
  mov dword [rbp-16], 0
  mov dword [rbp-12], 342
  mov dword [rbp-16], 5123123
  mov eax, dword [rbp-12]
  mov ebx, dword [rbp-16]
  add eax, ebx
  mov edi, eax
  call printInt
  mov eax, 0
  leave
  ret
