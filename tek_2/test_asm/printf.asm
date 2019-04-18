bits 64

section .text

global main
extern printf

main:
    push rbp
    mov rbp, rsp

    mov rax, 0
    mov rdi, str
    call printf

    mov ebx, 0
    mov eax, 1
    syscall

SECTION .rodata
str: db 'Hello OLIVIER!', 0Ah, 0
format: db '%s', 0 