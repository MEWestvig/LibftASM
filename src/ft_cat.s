%define SYSCALL(x)	0x2000000 | x
%define READ		3
%define WRITE		4
%define STDOUT		1
%define BUFF_SIZE	2048

section .bss
	buffer resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp
	push r13
	push r14

	mov r13, rdi

	.loop:
		mov rax, SYSCALL(READ)
		mov rdi, r13
		lea rsi, [rel buffer]
		mov rdx, BUFF_SIZE
		syscall

		jc .exit

		cmp rax, 0
		jle .exit

		mov r15, rax

		mov rax, SYSCALL(WRITE)
		mov rdi, STDOUT
		lea rsi, [rel buffer]
		mov rdx, r15
		syscall

		jc .exit

		cmp rax, 0
		jle .exit

		jmp .loop

	.exit:
		pop r14
		pop r13
		pop rbp
		ret
