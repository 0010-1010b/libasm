BITS 64

global ft_strcpy

ft_strcpy:
	xor rax, rax
	jmp .loop

.loop:
	cmp BYTE [rsi + rax], 0
	je exit
	mov al, [rsi + rax]
	mov [rdi + rax], al
	inc rax
	jmp .loop

exit:
	mov BYTE [rdi + rax], 0
	mov rax, rdi
	ret
