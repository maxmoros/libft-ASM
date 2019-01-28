#include "testrunner.h"

static char *manydots;

static void test_once(size_t len)
{
	char *s = calloc(len + 1, 1);
	memcpy(s, manydots, len);
	char *s_save = strdup(s);
	char *res = ft_strdup(s);
	assert(res != s); // new memory
	assert(!strcmp(s, res)); // same contents
	assert(!strcmp(s, s_save)); // didn't change s
	free(s);
	free(res);
	free(s_save);
}

void	test_ft_strdup(void)
{
	manydots = calloc(999999, 1);
	memset(manydots, '.', 999998);

	test_once(0);
	test_once(1);
	test_once(10);
	test_once(1024);
	test_once(999998);

	printf("%s: ok\n", __func__);
}
