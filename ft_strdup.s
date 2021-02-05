extern _ft_strlen
extern _malloc
section .text
	global _ft_strdup

_ft_strdup:
		mov rax, 0
		call _ft_strlen
		push rdi
		mov rdi, rax
		add rdi, 1
		call _malloc
		cmp rax, 0
		je _return
		pop r8
		mov rdx, -1
		call _loop
		mov BYTE[rax + rdx], 0
		ret
		
_return:
		ret
_loop:
		inc rdx
		cmp BYTE[r8 + rdx], 0
		jne _addf
		ret
_addf:
		mov bl, BYTE[r8 + rdx]
		mov BYTE[rax + rdx], bl
		jmp _loop
		ret
		