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
  mov byte [rbp-4], 0

  mov byte [rbp-4], 0

  mov byte [rbp-8], 1

  mov byte [rbp-8], 1

.LB1:
  movzx eax, byte [rbp-4]
  movzx ebx, byte [rbp-8]
  test al, al
  je .LB3
  mov eax, 1
  jmp .LB4
.LB3:
  mov eax, 0
.LB4:

  je .LB2
  jmp .LB1
.LB2:
.LB5:
  nop
  jmp .LB5
.LB6:
  mov eax, 0
.LB0:
  leave
  ret
