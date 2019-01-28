#include "testrunner.h"

static void test_once(char *s)
{
	size_t r1 = strlen(s);
	char *s_cpy = strdup(s);
	size_t r2 = ft_strlen(s);
	assert(r1 == r2);
	assert(!strcmp(s, s_cpy));
	free(s_cpy);
}

void test_ft_strlen(void)
{
	test_once("hi");
	test_once("");
	char *bigstring = calloc(999999, 1);
	memset(bigstring, '.', 999998);
	test_once(bigstring);
	free(bigstring);
	printf("%s: ok\n", __func__);
}
