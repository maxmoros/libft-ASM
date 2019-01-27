section	.text
		global ft_bzero

ft_bzero:
		cmp		rsi, 0
		jle		exit

clear:
		mov		byte[rdi], 0
		inc		rdi
		dec		rsi
		jnz		clear

exit:
		ret
