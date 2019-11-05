section .text
	global _ft_isupper

_ft_isupper:
	push rbp
	mov rbp, rsp
	cmp rdi, 'A'
	jl .notequal
	cmp rdi, 'Z'
	jg .notequal
	jmp .equal

	.notequal:
		mov rax, 0
		jmp .quit

	.equal:
		mov rax, 1
		jmp .quit

	.quit:
		pop rbp
		mov r12, rax
		ret
