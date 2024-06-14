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
  mov edi, 5
  call fac
  mov edi, eax
  call printInt
  mov eax, 0
  leave
  ret
fac:
  push rbp
  mov rbp, rsp
  mov dword [rbp-4], edi
  mov dword [rbp-8], 0
  mov dword [rbp-12], 0
  mov dword [rbp-8], 1
  mov eax, dword [rbp-4]
  mov dword [rbp-12], eax
.LB1:
  mov eax, dword [rbp-12]
  cmp eax, 0
  jle .LB2
  mov eax, dword [rbp-8]
  mov ebx, dword [rbp-12]
  imul eax, ebx
  mov dword [rbp-8], eax
  mov eax, dword [rbp-12]
  sub eax, 1
  mov dword [rbp-12], eax
  jmp .LB1
.LB2:
  mov ecx, dword [rbp-8]
  mov eax, ecx
.LB0:
  leave
  ret
