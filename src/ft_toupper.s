section .text
	global _ft_toupper
	extern _ft_islower

_ft_toupper:
	push rbp
	mov rbp, rsp
	call _ft_islower
	cmp rax, 0
	je .notlower
	mov rax, rdi
	sub rax, 32
	jmp .quit

	.notlower:
		mov rax, rdi

	.quit:
		pop rbp
		ret
