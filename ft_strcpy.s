section .text
			global _ft_strcpy
_ft_strcpy:
		mov rax, -1
		call _loop
		mov byte[rdi + rax], 0
		mov rax, rdi
		ret
_loop:
	inc rax
	cmp BYTE[rsi + rax], 0
	jne _copy
	ret

_copy:
	mov bl, byte[rsi + rax]
	mov byte[rdi + rax], bl
	jmp _loop
	ret