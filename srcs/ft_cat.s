%define		MACHO_SYSCALL(mode)	0x2000000 | mode
%define		READ				3
%define		WRITE				4
%define		STDOUT				0
%define		STDIN				1
%define		BUFF_SIZE			0x400

	global ft_cat

	section .bss
buffer:
	.buf	resb BUFF_SIZE

	section .text
ft_cat:
	mov		r12, rdi
	lea		r13, [rel buffer]
	mov		r14, BUFF_SIZE

cat_read:
	mov		rdi, r12
	mov		rsi, r13
	mov		rdx, r14

	mov		rax, MACHO_SYSCALL(READ)
	syscall
	jc		error

cat_write:
	mov		rdi, 0		;fd = 0
	mov		rsi, r13		;ptr to buf
	mov		rdx, rax		;read size

	mov		r15, rax

	mov		rax, MACHO_SYSCALL(WRITE)
	syscall
	jc		error

	cmp		r15, 0
	jg		cat_read
	jmp		end

error:
	mov		rax, -1

end:
	ret
