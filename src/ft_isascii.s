section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	jl .notequal
	cmp rdi, 127
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
