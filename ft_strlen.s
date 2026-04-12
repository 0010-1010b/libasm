BITS 64

global ft_strlen

ft_strlen:
	xor rax, rax
	jmp .loop

.loop:
	cmp BYTE [rdi + rax], 0
	je exit
	inc rax
	jmp .loop

exit:
	ret
