section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _ft_puts
	extern _malloc

_ft_strdup:
	push rbp
	mov rbp, rsp
	push r13
	push r14
	mov r14, rdi

	call _ft_strlen
	mov r13, rax

	mov rdi, r13
	inc rdi
	call _malloc
	cmp rax, 0
	je .exit

	mov rdi, rax
	mov rsi, r14
	mov rdx, r13
	call _ft_memcpy

	.exit:
		pop r14
		pop r13
		pop rbp
		ret
