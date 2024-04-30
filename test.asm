section .data
section .text
global _start


_start:
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32
    mov    dword [rbp-4], 1
    mov    dword [rbp-8], 2
    mov     eax,dword [rbp-8]
    mov    dword [rbp-4], eax
    mov    dword [rbp-12], 8
    mov    dword [rbp-16], 8
    mov    dword [rbp-20], 10
    mov     eax,dword [rbp-12]
    mov     edi, eax
    mov     eax, 60
    syscall