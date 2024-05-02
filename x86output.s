extern printInt
section .data
section .text
global main
sump:
  push rbp
  mov rbp, rsp
  mov dword [rbp-4], edi
  mov dword [rbp-8], esi
  mov dword [rbp-8], 1
  mov dword [rbp-12], 3
  mov dword [rbp-16], 6
  mov dword [rbp-20], 7
  mov eax, dword [rbp-16]
  pop rbp
  ret
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov dword [rbp-4], 3
  mov dword [rbp-8], 4
  mov dword [rbp-12], 9
  mov eax, dword [rbp-8]
  mov dword [rbp-4], eax
  mov eax, dword [rbp-4]
  mov edi, eax
  call printInt

  mov eax, dword [rbp-4]
  mov edi, eax
  mov eax, 60
  syscall
