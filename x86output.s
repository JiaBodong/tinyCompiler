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
  mov dword [rbp-4], 17
.LB1:
  cmp dword [rbp-4], 0
  jle .LB2
  mov eax, dword [rbp-4]
  sub eax, 2
  mov dword [rbp-4], eax
  jmp .LB1
.LB2:
  cmp dword [rbp-4], 0
  jge .LB4
.LB3:
  mov edi, 0
  call printInt
  mov eax, 0
  jmp .LB0
.LB4:
  mov edi, 1
  call printInt
  mov eax, 0
.LB5:
.LB0:
  leave
  ret
