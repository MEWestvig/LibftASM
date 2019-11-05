section .text
	global _ft_tolower
	extern _ft_isupper

_ft_tolower:
	push rbp
	mov rbp, rsp
	call _ft_isupper
	cmp rax, 0
	je .notupper
	mov rax, rdi
	add rax, 32
	jmp .quit

	.notupper:
		mov rax, rdi

	.quit:
		pop rbp
		ret
