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
  sub rsp, 32
  mov dword [rbp-4], 0
.LB1:
  mov eax, dword [rbp-4]
  mov dword [rbp-8], eax
  mov ebx, dword [rbp-8]
  cmp ebx, 10
  jge .LB2
  mov ebx, dword [rbp-4]
  mov dword [rbp-12], ebx
  mov ecx, dword [rbp-12]
  mov eax, 2
  mov ebx, 2
  cdq
  idiv ebx
  mov dword [rbp-16], edx
  mov ebx, dword [rbp-16]
  cmp ebx, 0
  jne .LB4
.LB3:
  mov ebx, dword [rbp-4]
  mov dword [rbp-20], ebx
  mov edi, dword [rbp-20]
  call printInt
.LB4:
  mov eax, dword [rbp-4]
  add eax, 1
  mov dword [rbp-4], eax
  jmp .LB1
.LB2:
  mov eax, 0
.LB0:
  leave
  ret
