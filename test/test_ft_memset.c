#include "testrunner.h"

void	test_ft_memset(void)
{
	char *ss[] = {
		"",
		".",
		"..",
		"...................................."
	};
	size_t nelems = (sizeof(ss) / sizeof(*(ss)));
	for (size_t i = 0; i < nelems; i++) {
		size_t sz = strlen(ss[i]) + 1;
		char *s = strdup(ss[i]);
		char *s2 = strdup(ss[i]);
		memset(s, 'a', 0);
		ft_memset(s2, 'a', 0);
		memset(s, 'a', sz - 1);
		ft_memset(s2, 'a', sz - 1);
		assert(!memcmp(s, s2, sz));
		memset(s, 'a', sz);
		ft_memset(s2, 'a', sz);
		assert(!memcmp(s, s2, sz));
		free(s);
		free(s2);
	}
	printf("%s: ok\n", __func__);
}
