BITS 64

SECTION .text

global _start

_start:
    mov eax, 4   
    mov ebx, 1    
    mov ecx, str
    mov edx, len
    int 0x80

    mov ebx, 0
    mov eax, 1
    int 0x80

SECTION .rodata
str: db 'Hello OLIVIER!', 0Ah, 0
len: equ $ - str