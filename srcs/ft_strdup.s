extern ft_strlen
extern malloc
global ft_strdup

	section .text
ft_strdup:
	cld
	mov		r12, rdi			;save src pointer
	call	ft_strlen
	cmp		rax, 0			;null src case
	je		end				;exit
	inc		rax				;room for null char
	mov		r13, rax			;save len for later
	mov		rdi,rax			;malloc size
	call	malloc
	mov		rdi, rax		;destination pointer
	mov		rsi, r12			;source pointer
	mov		rcx, r13			;n characters
	rep		movsb			;move n chars

end:
	ret
