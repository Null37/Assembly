section .text
    global _ft_read
_ft_read:
    mov rax, 0x2000003
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