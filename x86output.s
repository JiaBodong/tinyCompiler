extern printInt
extern printDouble
extern printString
extern readInt
extern readDouble
section .data
 epsilon dd 0.0000001
 FP1 dd 4.000000
 FP2 dd 50.000000
 Str1 db "apa", 0
 Str2 db "true", 0
 Str3 db "false", 0
section .text
global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], 4
  mov eax, dword [rbp-4]
  cmp eax, 3
  jg .LB2
  mov eax, 4
  cmp eax, 2
  je .LB2
  test al, al
  je .LB6
  mov eax, 1
  jmp .LB7
.LB6:
  mov eax, 0
.LB7:

  test al, al
  je .LB4
  mov eax, 1
  jmp .LB5
.LB4:
  mov eax, 0
.LB5:

  je .LB2
.LB1:
  movzx eax, al
  mov edi, eax
  call printBool
  jmp .LB3
.LB2:
  lea rdi, [Str1]
  call printString
.LB3:
  mov eax, 1
  cmp eax, 1
  mov dword [rbp-8], 1
  mov edi, dword [rbp-8]
  call dontCallMe
  or eax, 1
  movzx eax, al
  mov edi, eax
  call printBool
  movss xmm0, dword [FP1]
  movss xmm1, dword [FP2]
  ucomiss xmm0, xmm1
  jae .LB2
  mov dword [rbp-12], 2
  mov edi, dword [rbp-12]
  call dontCallMe
  test al, al
  je .LB8
  mov eax, 1
  jmp .LB9
.LB8:
  mov eax, 0
.LB9:

  and eax, 1
  movzx eax, al
  mov edi, eax
  call printBool
  mov eax, dword [rbp-4]
  cmp eax, 4
  jne .LB2
  xor eax, 1
  mov eax, 1
  cmp eax, 0
  test al, al
  je .LB12
  test al, al
  je .LB12
  mov eax, 1
  jmp .LB13
.LB12:
  mov eax, 0
.LB13:

  test al, al
  je .LB10
  mov eax, 1
  jmp .LB11
.LB10:
  mov eax, 0
.LB11:

  and eax, 1
  movzx eax, al
  mov edi, eax
  call printBool
  mov eax, 0
.LB0:
  leave
  ret
dontCallMe:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], edi
  mov eax, dword [rbp-4]
  mov dword [rbp-8], eax
  mov edi, dword [rbp-8]
  call printInt
  mov eax, eax
  leave
  ret
printBool:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov byte [rbp-4], al
  movzx eax, byte [rbp-4]
  cmp eax, 1
  je .LB15
  jne .LB15
.LB14:
  lea rdi, [Str2]
  call printString
  jmp .LB16
.LB15:
  lea rdi, [Str3]
  call printString
.LB16:
  nop
  leave
  ret
.LB0:
  leave
  ret
