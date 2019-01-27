%ifdef OSX
	%define SUCCESS 1
%elif LINUX
	%define SUCCESS 1024
%endif

section .text
	global	ft_isalpha

ft_isalpha:
	mov		rax, rdi
	cmp		al, 0x41
	jb		false
	cmp		al, 0x5a
	jbe		true
	cmp		al, 0x61
	jb		false
	cmp		al, 0x7a
	jbe		true

false:
	mov		rax, 0
	jmp		end

true:
	mov		rax, SUCCESS

end:
	ret
