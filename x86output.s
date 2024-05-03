extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 FP1 dd 1.0
 FP2 dd 2.000000
 FP3 dd 3.000000
 FP4 dd 4.000000
 FP5 dd 100.000000
section .text
global main
many_params:
  push rbp
  mov rbp, rsp
  sub rsp, 48
  movss dword [rbp-4], xmm0
  movss dword [rbp-8], xmm1
  movss dword [rbp-12], xmm2
  movss dword [rbp-16], xmm3
  movss dword [rbp-20], xmm4
  movss dword [rbp-24], xmm5
  movss dword [rbp-28], xmm6
  movss dword [rbp-32], xmm7
  movss xmm0, dword [rbp-4]
  cvtss2sd xmm0, xmm0
  call printDouble
  movss xmm0, dword [rbp-8]
  cvtss2sd xmm0, xmm0
  call printDouble
  movss xmm0, dword [rbp-16]
  cvtss2sd xmm0, xmm0
  call printDouble
  movss xmm0, dword [rbp-12]
  cvtss2sd xmm0, xmm0
  call printDouble
  movss xmm0, dword [rbp-20]
  cvtss2sd xmm0, xmm0
  call printDouble
  nop
  leave
  ret
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], 1
  mov eax, dword [rbp-4]
  mov dword [rbp-8], eax
  movss xmm0, dword [FP1]
  movss xmm0, xmm0
  movss xmm0, dword [FP2]
  movss xmm1, xmm0
  movss xmm0, dword [FP3]
  movss xmm2, xmm0
  movss xmm0, dword [FP4]
  movss xmm3, xmm0
  movss xmm0, dword [FP5]
  movss xmm4, xmm0
  movss xmm0, dword [FP5]
  movss xmm5, xmm0
  movss xmm0, dword [FP5]
  movss xmm6, xmm0
  movss xmm0, dword [FP5]
  movss xmm7, xmm0
  call many_params
  mov eax, 0
  leave
  ret
