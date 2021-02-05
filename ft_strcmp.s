section .text
	global _ft_strcmp

_ft_strcmp:
		mov rax, 0
		call _cmp
		ret
_cmp:
		mov cl, byte[rdi + rax]
		mov dl, byte[rsi + rax]
		cmp cl, 0 
		je _return
		cmp dl, 0
		je _return
		cmp cl, dl
		je _inc_l
		jmp _return
_inc_l:
		inc rax
		jmp _cmp
_return:
		movzx rax, cl
		movzx r10, dl
		sub rax, r10
		ret
