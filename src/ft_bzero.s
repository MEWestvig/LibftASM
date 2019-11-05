section .text
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp

	push rdi

	mov rcx, rsi
	mov rax, 0

	cld
	rep stosb

	pop rax
	pop rbp
	ret

