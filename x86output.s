extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 negmask dd 0x80000000
 epsilon dd 0.0000001
 Str1 db "&&", 0
 Str2 db "||", 0
 Str3 db "!", 0
 Str4 db "false", 0
 Str5 db "true", 0
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 80
  lea rdi, [Str1]
  call printString
  mov dword [rbp-4], 234234
  mov edi, dword [rbp-4]
  call test
  movzx ebx, al
  cmp ebx, 0
  je .LB1
  mov dword [rbp-8], 21321
  mov edi, dword [rbp-8]
  call test
  movzx ebx, al
  cmp ebx, 0
  je .LB1
  mov ebx, 1
  cmp ebx, 0
  je .LB1
  jmp .LB2

.LB1:
  and ebx, 0
  jmp .LB3

.LB2:
  and ebx, ebx

.LB3:
  mov dword [rbp-12], ebx
  movzx edi, byte [rbp-12]
  call printBool
  lea rdi, [Str2]
  call printString
  mov dword [rbp-16], -1
  mov edi, dword [rbp-16]
  call test
  movzx ebx, al
  cmp ebx, 1
  je .LB4

  mov dword [rbp-20], 0
  mov edi, dword [rbp-20]
  call test
  movzx ebx, al
  jmp .LB5

.LB4:
  or ebx, 1
  jmp .LB6

.LB5:
  or ebx, ebx

.LB6:
  mov dword [rbp-24], ebx
  movzx edi, byte [rbp-24]
  call printBool
  mov dword [rbp-28], -2
  mov edi, dword [rbp-28]
  call test
  movzx ebx, al
  cmp ebx, 1
  je .LB7

  mov dword [rbp-32], 1
  mov edi, dword [rbp-32]
  call test
  movzx ebx, al
  jmp .LB8

.LB7:
  or ebx, 1
  jmp .LB9

.LB8:
  or ebx, ebx

.LB9:
  mov dword [rbp-36], ebx
  movzx edi, byte [rbp-36]
  call printBool
  mov dword [rbp-40], 3
  mov edi, dword [rbp-40]
  call test
  movzx ebx, al
  cmp ebx, 1
  je .LB10

  mov dword [rbp-44], -5
  mov edi, dword [rbp-44]
  call test
  movzx ebx, al
  jmp .LB11

.LB10:
  or ebx, 1
  jmp .LB12

.LB11:
  or ebx, ebx

.LB12:
  mov dword [rbp-48], ebx
  movzx edi, byte [rbp-48]
  call printBool
  mov dword [rbp-52], 234234
  mov edi, dword [rbp-52]
  call test
  movzx ebx, al
  cmp ebx, 1
  je .LB13

  mov dword [rbp-56], 21321
  mov edi, dword [rbp-56]
  call test
  movzx ebx, al
  jmp .LB14

.LB13:
  or ebx, 1
  jmp .LB15

.LB14:
  or ebx, ebx

.LB15:
  mov dword [rbp-60], ebx
  movzx edi, byte [rbp-60]
  call printBool
  lea rdi, [Str3]
  call printString
  mov byte [rbp-64], 1
  movzx edi, byte [rbp-64]
  call printBool
  mov byte [rbp-68], 0
  movzx edi, byte [rbp-68]
  call printBool
  mov eax, 0
  leave
  ret
printBool:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], edi
  movzx ebx, byte [rbp-4]
  xor ebx, 1
  cmp ebx, 0
  je .LB17
.LB16:
  lea rdi, [Str4]
  call printString
  jmp .LB18
.LB17:
  lea rdi, [Str5]
  call printString
.LB18:
  nop
  leave
  ret
.LB0:
  leave
  ret
test:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], edi
  mov ebx, dword [rbp-4]
  mov dword [rbp-8], ebx
  mov edi, dword [rbp-8]
  call printInt
  mov ebx, dword [rbp-4]
  cmp ebx, 0
  setg al
  movzx ebx, al
  mov eax, ebx
  leave
  ret
