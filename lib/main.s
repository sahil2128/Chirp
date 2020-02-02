; I might implement features in the future,
; so I woudn't need assembly in the library source
section .text
    global _start
    global raw_syscall

; Temporary for this one compiler
_start:
mov 0,rbp
pop rdi
mov rsi,rsp
and rsp,-16
call entry
mov rdi,rax
mov rax,60
syscall
ret

raw_syscall:
    mov rax,rdi
    mov rdi,rsi
    mov rsi,rdx
    mov rdx,rcx
    mov r10,r8
    mov r8,r9
    syscall
    ret