section .text
	global ft_toupper

ft_toupper:
	mov		rax, rdi
	cmp		al, 0x61
	jb		end
	cmp		al, 0x7a
	ja		end
	sub		rax, 0x20

end:
	ret 
