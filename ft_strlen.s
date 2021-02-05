section .text
			global _ft_strlen
_ft_strlen:
			mov rax, -1
			call _loop
			ret
_loop:
		inc rax
		cmp BYTE[rdi + rax], 0
		jne _loop
		ret
