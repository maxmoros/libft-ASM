#ifndef TESTRUNNER_H
# define TESTRUNNER_H
# include "libfts.h"
# include <assert.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void test_ft_bzero(void);
void test_ft_strcat(void);
void test_ft_isalpha(void);
void test_ft_isdigit(void);
void test_ft_isalnum(void);
void test_ft_isascii(void);
void test_ft_isprint(void);
void test_ft_toupper(void);
void test_ft_tolower(void);
void test_ft_puts(void);
void test_ft_strlen(void);
void test_ft_memset(void);
void test_ft_memcpy(void);
void test_ft_strdup(void);
void test_ft_cat(void);

#define MILLION 1000000
#define BILLION 1000000000
#endif
