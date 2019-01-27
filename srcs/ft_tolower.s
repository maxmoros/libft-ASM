section .text
	global ft_tolower

ft_tolower:
	mov		rax, rdi
	cmp		al, 0x41
	jb		end
	cmp		al, 0x5a
	ja		end
	add		rax, 0x20

end:
	ret 
