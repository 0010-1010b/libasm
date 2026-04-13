BITS 64

global ft_strlen

; int ft_strlen(const char *rdi);
ft_strlen:
	mov rax, 0

.loop:
	cmp BYTE [rdi + rax], 0
	je .exit
	inc rax
	jmp .loop

.exit:
	ret
