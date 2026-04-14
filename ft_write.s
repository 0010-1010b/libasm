BITS 64

; Position independant executable (no-pie)

extern __errno_location

global ft_write

; ssize_t ft_write(int rdi, const void *rsi, size_t rdx);
ft_write:
	cmp rsi, 0
	je .error
	mov rax, 1
	syscall
	cmp rax, 0
	jl .error
	ret

.error:
	neg rax
	mov rbx, rax
	call __errno_location WRT ..plt ; With reference to procedure linkage table
	mov [rax], rbx
	mov rax, -1
	ret
