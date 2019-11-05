section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp
	cmp rdi, '0'
	jl .notequal
	cmp rdi, '9'
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
