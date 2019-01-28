#include "libftasm.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

void	ft_putstr(char *str);

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

int		ck_puts(const char *s)
{
	puts(s);
	ft_puts(s);
	return (1);
}

int		ck_strlen(char *str)
{
	printf("\tft_ = %lu, sys = %lu\n", ft_strlen(str), strlen(str));
	return (ft_strlen(str) == strlen(str));
}

int		ck_memset(void *s, int c, size_t n)
{
	char	*A;
	char	*B;

	A = strdup((char*)s);
	B = strdup((char*)s);
	printf("\tft_ = %s, sys = %s\n", A, B);
	printf("\tft_ = %s, sys = %s\n", ft_memset(A, c, n), memset(B, c, n));
	return (!strcmp(A, B));
}

int		ck_memcpy(void *dest, const void *src, size_t n)
{
	char	*A;
	char	*B;

	A = strdup((char*)dest);
	B = strdup((char*)dest);
	printf("\tft_ = %s, sys = %s\n", A, B);
	A = ft_memcpy(A, src, n);
	B = ft_memcpy(B, src, n);
	printf("\tft_ = %s, sys = %s\n", A, B);
	return (!strcmp(A, B));
}

int		ck_strdup(const char *s)
{
	char	*A;
	char	*B;

	printf("\tstr = \"%s\"\n", s);
	A = ft_strdup(s);
	B = strdup(s);
	printf("\tft_ = %s, sys = %s\n", A, B);
	return (!strcmp(A, B));
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	confirm(int i)
{
	if (i)
		ft_putstr("\x1b[32mOK! \x1b[0m");
	else
		ft_putstr("\x1b[31mKO! \x1b[0m");
}

void	run_tests()
{
	ft_putstr("\nft_bzero:\n");
	confirm(ck_bzero(0x42424242, sizeof(int)));
	ft_putstr("\n\nft_strcat:\n");
	confirm(ck_strcat("abc", "def"));
	ft_putstr("\n\nft_isalpha:\n");
	confirm(ck_isalpha('Z'));
	confirm(ck_isalpha(';'));
	ft_putstr("\n\nft_isdigit:\n");
	confirm(ck_isdigit('1'));
	confirm(ck_isdigit('0'));
	confirm(ck_isdigit(')'));
	confirm(ck_isdigit('T'));
	ft_putstr("\n\nft_isalnum:\n");
	confirm(ck_isalnum('Z'));
	confirm(ck_isalnum(';'));
	confirm(ck_isalnum('0'));
	confirm(ck_isalnum(')'));
	ft_putstr("\n\nft_isascii:\n");
	confirm(ck_isascii('Z'));
	confirm(ck_isascii(';'));
	ft_putstr("\n\nft_toupper:\n");
	confirm(ck_toupper('Z'));
	confirm(ck_toupper(';'));
	confirm(ck_toupper('a'));
	ft_putstr("\n\nft_tolower:\n");
	confirm(ck_tolower('Z'));
	confirm(ck_tolower(']'));
	confirm(ck_tolower('a'));
	ft_putstr("\n\nft_puts:\n");
	confirm(ck_puts("yolo"));
	ft_putstr("\n\nft_strlen:\n");
	confirm(ck_strlen("yolo"));
	confirm(ck_strlen("y"));
	confirm(ck_strlen(""));
	confirm(ck_strlen("yolo56"));
	ft_putstr("\n\nft_memset:\n");
	confirm(ck_memset("yolo", 'a', 3));
	ft_putstr("\n\nft_memcpy:\n");
	confirm(ck_memcpy("maxmaxmax", "4242", 4));
	ft_putstr("\n\nft_strdup:\n");
	confirm(ck_strdup(""));
	confirm(ck_strdup("maxmaxmax\0"));
}

int		main(void)
{
	run_tests();
	return (0);
}
