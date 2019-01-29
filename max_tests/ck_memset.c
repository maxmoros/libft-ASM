#include "asmtests.h"

static void		test_memset(void *s, int c, size_t n)
{
	char	*A;
	char	*B;

	A = strdup((char*)s);
	B = strdup((char*)s);
	ft_memset(A, c, n);
	memset(B, c, n);
	if (strcmp(A, B))
	{
		ft_putstr("\x1b[31mKO!\x1b[0m\n");
		ft_putstr("failed at \'");
		ft_putstr((char*)s);
		ft_putstr("\', got \'");
		ft_putstr(A);
		ft_putstr("\', should be \'");
		ft_putstr(B);
		ft_putstr("\'\n");
	}
	assert(!strcmp(A, B));
}

void			ck_memset(void)
{
	ft_putstr("ft_memset: ");
	test_memset("maxmax", 'a', 3);	
	test_memset("this is a test", 'b', 8);	
	ft_putstr("\x1b[32mOK!\x1b[0m\n");
}
