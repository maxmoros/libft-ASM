extern	ft_isalpha
extern	ft_isdigit

section .text
	global	ft_isalnum

ft_isalnum:
	xor		rax, rax
	call	ft_isalpha
	cmp		rax, 0
	jne		end
	call	ft_isdigit

end:
	ret
