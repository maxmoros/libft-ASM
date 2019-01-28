#include "testrunner.h"

static FILE *a6_;
static FILE *b1_;
static FILE *empty;
static FILE *c20nl;

static void make_abc_test_files()
{
	a6_ = fopen("/tmp/a6_.txt", "w+");
	b1_ = fopen("/tmp/b1_.txt", "w+");
	empty = fopen("/tmp/empty.txt", "w+");
	c20nl = fopen("/tmp/c20nl.txt", "w+");
	fprintf(a6_, "aaaaaa_");
	fprintf(b1_, "b_");
	fprintf(c20nl, "cccccccccccccccccccc\n");
	rewind(a6_);
	rewind(b1_);
	rewind(c20nl);
}

static void test_ft_cat_accuracy(void)
{
	make_abc_test_files();

	freopen("/tmp/stdout_cpy", "w", stdout);
	ft_cat(fileno(a6_));
	ft_cat(fileno(b1_));
	ft_cat(fileno(empty));
	ft_cat(-1);
	ft_cat(fileno(c20nl));
	freopen("/dev/tty", "w", stdout);

	FILE *f = fopen("/tmp/stdout_cpy", "r");
	char *line = calloc(100, 1);
	char *res = fgets(line, 99, f);
	assert(res != NULL);
	assert(!strcmp(res, "aaaaaa_b_cccccccccccccccccccc\n"));

	fclose(a6_);
	fclose(b1_);
	fclose(empty);
	fclose(c20nl);
	fclose(f);
	free(line);
}

static void test_ft_cat_bigfile_performance(void)
{
	int nb_100byte_lines = 100000;
	FILE *bigfile = fopen("/tmp/bigfile.txt", "w+");
	for (int i = 0; i < nb_100byte_lines; i++)
	{
	  fprintf(bigfile, "--------------------this line is one hundred bytes long (including the newline)--------------------\n");
	}
	rewind(bigfile);

	freopen("/tmp/stdout_cpy", "w", stdout);
	ft_cat(fileno(bigfile));
	freopen("/dev/tty", "w", stdout);

	struct stat statbuf;
	stat("/tmp/stdout_cpy", &statbuf);
	assert(statbuf.st_size == nb_100byte_lines * 100);
}

void test_ft_cat(void)
{
	test_ft_cat_accuracy();
	test_ft_cat_bigfile_performance();
	printf("%s: ok\n", __func__);
}
