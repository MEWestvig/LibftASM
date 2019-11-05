section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp

	mov al, 0
	mov rcx, -1

	cld
	repne scasb

	mov rax, -2
	sub rax, rcx

	pop rbp
	ret