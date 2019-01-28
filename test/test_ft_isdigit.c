#include "testrunner.h"

static void test_once(int c)
{
	int r1 = isdigit(c);
	int r2 = ft_isdigit(c);
	if (r1 != r2)
		printf("fail at \'%c\'\n", c);
	assert(r1 == r2);
}

void test_ft_isdigit(void)
{
	for (int i = -555; i < 555; i++)
		test_once(i);
	test_once(EOF);
	test_once(INT_MIN);
	test_once(INT_MAX);
	printf("%s: ok\n", __func__);
}
