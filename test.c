#include "libftasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

// Make this more complex
int		ck_bzero(int i, size_t n)
{
	int		x;
	int		y;

	x = i;
	y = i;
	bzero(&x, n);
	ft_bzero(&y, n);
	return (x == y);
}

int		ck_strcat(char *a, char *b)
{
	char	*A1;
	char	*A2;
	char	*B;

	A1 = malloc(sizeof(char) * 7);
	A2 = malloc(sizeof(char) * 7);
	B = malloc(sizeof(char) * 4);
	A1 = strcpy(A1, a);
	A2 = strcpy(A2, a);
	B = strcpy(B, b);
	strcat(A1, B);
	ft_strcat(A2, B);
	return (!strcmp(A1, A2));
}

int		ck_isalpha(char c)
{
	return (ft_isalpha(c) == isalpha(c));
}

int		ck_isdigit(char c)
{
	return (ft_isdigit(c) == isdigit(c));
}

int		ck_isalnum(char c)
{
	return (ft_isalnum(c) == isalnum(c));
}

int		ck_isascii(char c)
{
	return (ft_isascii(c) == isascii(c));
}

int		ck_toupper(int c)
{
	return (ft_toupper(c) == toupper(c));
}

int		ck_tolower(int c)
{
	return (ft_tolower(c) == tolower(c));
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	confirm(int i)
{
	if (i)
		ft_putstr("\x1b[32mOK!\n\x1b[0m");
	else
		ft_putstr("\x1b[31mKO!\n\x1b[0m");
}

void	run_tests()
{
	ft_putstr("ft_bzero\n");
	confirm(ck_bzero(0x42424242, sizeof(int)));
	ft_putstr("ft_strcat\n");
	confirm(ck_strcat("abc", "def"));
	ft_putstr("ft_isalpha\n");
	confirm(ck_isalpha('Z'));
	confirm(ck_isalpha(';'));
	ft_putstr("ft_isdigit\n");
	confirm(ck_isdigit('1'));
	confirm(ck_isdigit('0'));
	confirm(ck_isdigit(')'));
	confirm(ck_isdigit('T'));
	ft_putstr("ft_isalnum\n");
	confirm(ck_isalnum('Z'));
	confirm(ck_isalnum(';'));
	confirm(ck_isalnum('0'));
	confirm(ck_isalnum(')'));
	ft_putstr("ft_isascii\n");
	confirm(ck_isascii('Z'));
	confirm(ck_isascii(';'));
	ft_putstr("ft_toupper\n");
	confirm(ck_toupper('Z'));
	confirm(ck_toupper(';'));
	confirm(ck_toupper('a'));
	ft_putstr("ft_tolower\n");
	confirm(ck_tolower('Z'));
	confirm(ck_tolower(']'));
	confirm(ck_tolower('a'));
}

int		main(void)
{
	run_tests();
	return (0);
}
