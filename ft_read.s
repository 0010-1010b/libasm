BITS 64

extern __errno_location

global ft_read

; ssize_t ft_read(int rdi, void *rsi, size_t rdx);
ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl .error
	ret

.error:
	neg rax
	mov rbx, rax
	call __errno_location WRT ..plt
	mov [rax], rbx
	mov rax, -1
	ret
