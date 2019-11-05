section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push rbp
	mov rbp, rsp
	call _ft_isalpha
	cmp rax, 0
	jnz .quit
	call _ft_isdigit

	.quit:
		pop rbp
		ret
