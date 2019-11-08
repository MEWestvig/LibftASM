section .text
	global _ft_strcat

_ft_strcat:
	push rbp
	mov rbp, rsp
	push rdi
	push rsi
	mov r14, rdi

	.loop:
		cmp BYTE [rdi], 0
		jz .copy
		inc rdi
		jmp .loop
	
	.copy:
		cmp BYTE [rsi], 0
		jz .end
		mov r8b, [rsi]
		mov [rdi], r8b
		inc rdi
		inc rsi
		jmp .copy
	
	.end:
		mov BYTE [rdi], 0
		pop rsi
		pop rax
		pop rbp
		ret
