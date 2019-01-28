#include "testrunner.h"

static void test_accuracy(size_t len)
{
	char *s1 = calloc(len + 1, 1);
	memset(s1, '.', len);
	char *s2 = strdup(s1);

	bzero(s1, 0);
	ft_bzero(s2, 0);
	assert(!memcmp(s1, s2, len + 1));

	bzero(s1, len);
	ft_bzero(s2, len);
	assert(!memcmp(s1, s2, len + 1));

	bzero(s1, len / 2);
	ft_bzero(s2, len / 2);
	assert(!memcmp(s1, s2, len + 1));

	bzero(s1, len + 1);
	ft_bzero(s2, len + 1);
	assert(!memcmp(s1, s2, len + 1));

	free(s1);
	free(s2);
}

static void perf_try(void *input, size_t sz, size_t times)
{
	printf("running %lu times on %lu byte input\n", times, sz);

	time_t start = clock();
	for (size_t i = 0; i < times; i++)
		bzero(input, sz);
	time_t theirs = clock() - start;
	printf("bzero: %f\n", (double)theirs / CLOCKS_PER_SEC);

	start = clock();
	for (size_t i = 0; i < times; i++)
		ft_bzero(input, sz);
	time_t ours = clock() - start;
	printf("ft_bzero: %f\n", (double)ours / CLOCKS_PER_SEC);
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

void	test_ft_bzero(void)
{
	test_accuracy(0);
	test_accuracy(1);
	test_accuracy(2);
	test_accuracy(49);
	test_accuracy(99998);
	//test_performance();
	printf("%s: ok\n", __func__);
}
