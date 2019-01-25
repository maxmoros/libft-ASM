#include "inc/libftasm.h"
#include <unistd.h>
#include <strings.h>

int		main(void)
{
	int		x;
	int		y;

	x = 0xFFBB9977;
	y = x;
	bzero(&x, sizeof(int));
	ft_bzero(&y, sizeof(int));
	if (x == y)
		write(1, "OK!\n", 4);
	else
		write(1, "KO!\n", 4);
	return (0);
}
