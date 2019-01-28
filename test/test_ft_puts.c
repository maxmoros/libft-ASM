#include "testrunner.h"

static void test_once(char *input)
{
	if (input == NULL)
		input = "(null)";
	size_t len = strlen(input);
	char *line = calloc(len + 2, 1);
	freopen("/tmp/stdout_cpy", "w", stdout);
	ft_puts(input);
	freopen("/dev/tty", "w", stdout);
	FILE *f = fopen("/tmp/stdout_cpy", "r");
	char *res = fgets(line, len + 2, f);
	assert(res != NULL);
	size_t nl_idx = strcspn(res, "\n");
	assert(nl_idx == len);
	res[nl_idx] = '\0';
	assert(!strcmp(res, input));
	free(line);
	fclose(f);
}


void test_ft_puts(void)
{
	test_once("");
	test_once(NULL);
	test_once("hi");
	char *bigstring = calloc(999999, 1);
	memset(bigstring, '.', 999998);
	test_once(bigstring);
	free(bigstring);
	printf("%s: ok\n", __func__);
}
