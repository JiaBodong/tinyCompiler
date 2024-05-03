extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 FP1 dd 3.000000
 FP2 dd 4.000000
 FP3 dd 9.000000
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 32
  mov dword [rbp-4], -3
  mov dword [rbp-8], 4
  mov dword [rbp-16], 7
  mov dword [rbp-12], -999
  mov eax, dword [rbp-8]
  mov dword [rbp-4], eax
  movss xmm0, dword [FP1]
  movss dword [rbp-20], xmm0
  movss xmm0, dword [FP2]
  movss dword [rbp-20], xmm0
  movss xmm0, dword [FP3]
  movss dword [rbp-20], xmm0
  mov eax, dword [rbp-4]
  mov edi, eax
  call printInt
  mov eax, dword [rbp-12]
  mov edi, eax
  call printInt
  movss xmm0, dword [rbp-20]
  cvtss2sd xmm0, xmm0
  call printDouble
  mov eax, 1
  leave
  ret
