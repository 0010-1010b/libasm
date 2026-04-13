BITS 64

global ft_strcpy

; char *ft_strcpy(char *rdi, char *rsi);
ft_strcpy:
	mov rcx, 0

.loop:
	mov dl, [rsi + rcx]
	mov [rdi + rcx], dl
	inc rcx
	cmp BYTE dl, 0
	jne .loop

.exit:
	mov rax, rdi
	ret
