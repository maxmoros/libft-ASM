#include "testrunner.h"

static char *manydots;

static void test_accuracy(size_t len)
{
	char *s = calloc(len + 1, 1);
	char *s2 = calloc(len + 1, 1);
	memcpy(s, manydots, len);
	char *res = ft_memcpy(s2, manydots, len);
	assert(res == s2);
	assert(!strcmp(s, s2));
	free(s);
	free(s2);
}

static void perf_try(void *dst, size_t sz, size_t times)
{
	printf("running %lu times on %lu byte input\n", times, sz);

	time_t start = clock();
	for (size_t i = 0; i < times; i++)
		memcpy(dst, manydots, sz);
	time_t theirs = clock() - start;
	printf("memcpy: %f\n", (double)theirs / CLOCKS_PER_SEC);

	start = clock();
	for (size_t i = 0; i < times; i++)
		ft_memcpy(dst, manydots, sz);
	time_t ours = clock() - start;
	printf("ft_memcpy: %f\n", (double)ours / CLOCKS_PER_SEC);
	printf("loss: %.3f\n", ((double)ours / times) / ((double)theirs / times));
}

static void test_performance(void)
{
	char tiny[1];
	char verysmall[16];
	char small[128];
	char medium[2048];
	char big[32768];
	char huge[32768*8];

	perf_try(tiny, sizeof(tiny), 100 * MILLION);
	perf_try(verysmall, sizeof(verysmall), 100 * MILLION);
	perf_try(small, sizeof(small), 100 * MILLION);
	perf_try(medium, sizeof(medium), 10 * MILLION);
	perf_try(big, sizeof(big), MILLION);
	perf_try(huge, sizeof(huge), MILLION / 10);
}

void	test_ft_memcpy(void)
{
	manydots = calloc(32768*8 + 1, 1);
	memset(manydots, '.', 32768*8);

	test_accuracy(0);
	test_accuracy(1);
	test_accuracy(10);
	test_accuracy(1024);
	test_accuracy(99998);

	//test_performance();
	printf("%s: ok\n", __func__);
}
