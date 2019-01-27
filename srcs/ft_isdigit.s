%ifdef OSX
	%define SUCCESS 1
%elif LINUX
	%define SUCCESS 1024
%endif

section .text
	global	ft_isdigit

ft_isdigit:
	mov		rax, rdi
	cmp		al, 0x30
	jb		false
	cmp		al, 0x39
	ja		false

true:
	mov		rax, SUCCESS
	jmp		end

false:
	mov		rax, 0

end:
	ret
