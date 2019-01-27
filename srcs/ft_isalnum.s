extern	ft_isalpha
extern	ft_isdigit

%ifdef OSX
	%define SUCCESS 1
%elif LINUX
	%define SUCCESS 8
%endif

section .text
	global	ft_isalnum

ft_isalnum:
	call	ft_isalpha
	cmp		rax, 0
	jne		end
	call	ft_isdigit

end:
	ret
