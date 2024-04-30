sump:
  push rbp
  mov rbp, rsp
  sub rsp, 32
  mov DWORD PTR [rbp-4], edi
  mov DWORD PTR [rbp-8], esi
  mov DWORD PTR [rbp-8], 1
  mov DWORD PTR [rbp-12], 3
  mov DWORD PTR [rbp-16], 6
  mov DWORD PTR [rbp-20], 7
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov DWORD PTR [rbp-4], 3
  mov DWORD PTR [rbp-8], 4
  mov DWORD PTR [rbp-12], 9
  mov eax, DWORD PTR [rbp-8]
  mov DWORD PTR [rbp-4], eax
  mov eax, DWORD PTR [rbp-4]
  mov edi, eax
  mov eax, DWORD PTR [rbp-8]
  mov esi, eax
  call sump
