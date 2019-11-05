section .text
	global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp
	cmp rdi, 32
	jl .notequal
	cmp rdi, 126
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
