extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 epsilon dd 0.0000001
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov edi, 7
  call fact
  mov edi, eax
  call printInt
  mov dword [rbp-4], 2
  mov eax, dword [rbp-4]
  mov ebx, dword [rbp-4]
  sub ebx, 1
  mov edi, ebx
  call fact
  mov ebx, eax
  add n, ebx
  mov eax, n
  mov dword [rbp-4], eax
  mov eax, 0
  leave
  ret
fact:
  push rbp
  mov rbp, rsp
  mov dword [rbp-4], edi
  mov dword [rbp-8], 0
  mov dword [rbp-12], 0
  mov dword [rbp-8], 1
  mov dword [rbp-12], 1
.LB1:
  mov eax, dword [rbp-8]
  cmp eax, dword [rbp-4]
  jg .LB2
  mov eax, dword [rbp-12]
  imul eax, dword [rbp-8]
  mov dword [rbp-12], eax
  mov eax, dword [rbp-8]
  add eax, 1
  mov dword [rbp-8], eax
  jmp .LB1
.LB2:
  mov eax, dword [rbp-12]
.LB0:
  leave
  ret
