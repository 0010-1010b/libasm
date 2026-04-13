BITS 64

global ft_strcmp

; int ft_strcmp(const char *rdi, const char *rsi);
ft_strcmp:
	mov rax, 0

.loop:
	mov al, [rdi]
	mov bl, [rsi]
	cmp al, bl
	jne .diff

	cmp al, 0
	je .exit

	inc rdi
	inc rsi
	jmp .loop

.diff:
	movzx eax, al
	movzx ebx, bl
	sub eax, ebx
	ret

.exit:
	mov eax, 0
	ret
