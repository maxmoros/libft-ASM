#include "testrunner.h"

static char *dest1;
static char *dest2;
static char *src;

static void test_once(size_t dest_len, size_t src_len)
{
	src[src_len] = '\0';
	memset(dest1, 'a', dest_len);
	memset(dest2, 'a', dest_len);
	dest1[dest_len] = '\0';
	dest2[dest_len] = '\0';
	strcat(dest1, src);
	char *res = ft_strcat(dest2, src);
	assert(dest2 == res);
	assert(!memcmp(dest1, dest2, 200000 + 1));
	src[src_len] = '!';
}

void test_ft_strcat(void)
{
	dest1 = calloc(200000 + 1, 1);
	dest2 = calloc(200000 + 1, 1);
	src = calloc(100000 + 1, 1);
	memset(src, '!', 99999);
	test_once(0, 0);
	test_once(1, 0);
	test_once(0, 1);
	test_once(99999, 99999);
	test_once(99999, 0);
	test_once(0, 99999);
	free(dest1);
	free(dest2);
	free(src);
	printf("%s: ok\n", __func__);
}
