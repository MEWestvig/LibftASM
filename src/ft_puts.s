%define SYSCALL(x)	0x2000000 | x
%define WRITE 4
%define STDOUT 1

section .data
	eol db 10

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	push rdi
	mov r14, rdi

	.len:
		call _ft_strlen
		push rax
		mov r13, rax
	
	.write:
		mov rax, SYSCALL(WRITE)
		mov rdi, STDOUT
		mov rsi, r14
		mov rdx, r13
		syscall

	.newline:
		mov rax, SYSCALL(WRITE)
		lea rsi, [rel eol]
		mov rdx, 1
		syscall
	
	.end:
		pop rax
		pop r13
		pop rbp
		ret
