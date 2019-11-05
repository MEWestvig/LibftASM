section .text
	global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	push rdi

	mov rcx, rdx
	mov rax, rsi

	cld
	rep stosb

	pop rax
	pop rbp
	ret