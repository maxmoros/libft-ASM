#include "asmtests.h"

static char *d1;
static char *d2;
static char *src;

static void		test_strcat(size_t dlen, size_t slen)
{
	src[slen] = '\0';
	memset(d1, 'a', dlen);
	memset(d2, 'a', dlen);
	d1[dlen] = '\0';
	d2[dlen] = '\0';
	strcat(d1, src);
	char *res = ft_strcat(d2, src);
	if (d2 != res || memcmp(d1, d2, 21))
	{
		ft_putstr("\x1b[31mKO!\x1b[0m\n");
		ft_putstr("failed at dlen=\'");
		ft_putnbr((int)dlen);
		ft_putstr(", slen=\'");
		ft_putnbr((int)slen);
		ft_putstr("\'\n");
	}
	assert(d2 == res);
	assert(!memcmp(d1, d2, 21));
	src[slen] = '!';
}

void			ck_strcat(void)
{
	ft_putstr("ft_strcat: ");
	d1 = calloc(21, 1);
	d2 = calloc(21, 1);
	src = calloc(11, 1);
	memset(src, 'x', 9);
	test_strcat(0, 0);
	test_strcat(0, 1);
	test_strcat(1, 0);
	test_strcat(1, 1);
	test_strcat(0, 9);
	test_strcat(9, 0);
	test_strcat(9, 9);
	free(d1);
	free(d2);
	free(src);
	ft_putstr("\x1b[32mOK!\x1b[0m\n");
}
