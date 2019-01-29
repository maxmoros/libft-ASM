#include "asmtests.h"

void	run_tests()
{
	ck_bzero();
	ck_strcat();
	ck_isto(ft_isalpha, isalpha, "ft_isalpha");
	ck_isto(ft_isdigit, isdigit, "ft_isdigit");
	ck_isto(ft_isalnum, isalnum, "ft_isalnum");
	ck_isto(ft_isascii, isascii, "ft_isascii");
	ck_isto(ft_toupper, toupper, "ft_toupper");
	ck_isto(ft_tolower, tolower, "ft_tolower");
	ck_puts();
	ck_strlen();
	ck_memset();
	ck_memcpy();
	ck_strdup();
}

int		main(void)
{
	run_tests();
	return (0);
}
