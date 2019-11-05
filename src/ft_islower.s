section .text
	global _ft_islower

_ft_islower:
	push rbp
	mov rbp, rsp
	cmp rdi, 'a'
	jl .notequal
	cmp rdi, 'z'
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
