section .text
	global _ft_isalpha
	extern _ft_islower
	extern _ft_isupper

_ft_isalpha:
	push rbp
	mov rbp, rsp
	call _ft_islower
	cmp rax, 0
	jnz .quit
	call _ft_isupper

	.quit:
		pop rbp
		ret
