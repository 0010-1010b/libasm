BITS 64

extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

; char *ft_strdup(const char *rdi);
ft_strdup:
	push rdi
	call ft_strlen
	inc rax ; '\0'

	; before calling malloc, rdi must be of the string size
	mov rdi, rax
	call malloc WRT ..plt
	cmp rax, 0
	je .fail

	mov rdi, rax
	pop rsi

	; char *ft_strcpy(char *rdi, char *rsi);
	call ft_strcpy
	ret

.fail:
	pop rdi
	mov rax, 0
	ret
