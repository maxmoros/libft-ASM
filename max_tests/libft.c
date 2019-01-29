#include "asmtests.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

static void	ft_putdig(int n)
{
	if (!n)
		return ;
	ft_putdig(n / 10);
	ft_putchar('0' + n % 10);
}

void		ft_putnbr(int n)
{
	if (!n)
		write(1, "0", 1);
	else if (n == -2147483648)
	{
		write(1, "-", 1);
		ft_putdig(21474);
		ft_putdig(83648);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	ft_putdig(n);
}
