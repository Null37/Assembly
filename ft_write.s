section .text
    global _ft_write
_ft_write:
    mov rax, 0x2000004
    syscall
    jnc _return
    push rax
    extern ___error
    call ___error
    pop r10
    mov [rax],r10
    mov rax, -1

_return:
    ret