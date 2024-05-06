extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 FP1 dd 102.000000
 FP2 dd 11.000000
 FP3 dd 10.000000
 FP4 dd 100.000000
 FP5 dd 3.000000
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  movss xmm0, dword [FP1]
  movss dword [rbp-4], xmm0
  mov dword [rbp-8], 1
  movss xmm0, dword [rbp-4]
  movss xmm1, dword [FP2]
  ucomiss xmm0, xmm1
  jb .LB1
  movss xmm0, dword [rbp-4]
  movss xmm1, dword [FP3]
  ucomiss xmm0, xmm1
  jb .LB1
  movss xmm0, dword [FP4]
  movss xmm1, dword [rbp-4]
  ucomiss xmm0, xmm1
  jae .LB2
.LB1:
  movss xmm0, dword [FP5]
  movss dword [rbp-12], xmm0
  movss xmm0, dword [rbp-12]
  cvtss2sd xmm0, xmm0
  call printDouble
.LB2:
  movss xmm0, dword [rbp-4]
  movss xmm1, dword [FP4]
  ucomiss xmm0, xmm1
  jbe .LB4
  cmp dword [rbp-8], 2
  jge .LB4
.LB3:
  mov eax, dword [rbp-8]
  mov edi, eax
  call printInt
.LB4:
  mov eax, 0
  leave
  ret
