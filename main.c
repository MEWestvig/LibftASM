#include "libftasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static void		test_isall(void)
{
	int			tests[11] = {'a', 'A', 'G', 'b', '?', 'h', '0', '9', '5', '\0', 0xff};
	int			p;
	char		c;

	printf("%s", "testing for ft_is*...\n");
	p = 0;
	while  (p < 11)
	{
		c = (char)tests[p++];
		printf("char: %c\nft_islower: %d\nft_isupper: %d\nft_isalpha: %d\nft_isdigit: %d\nft_isalnum: %d\nft_isascii: %d\nft_isprint: %d\nft_toupper: %c\nft_tolower: %c\n\n",
				c, ft_islower(c),ft_isupper(c),ft_isalpha(c),ft_isdigit(c),ft_isalnum(c),ft_isascii(c),ft_isprint(c), ft_toupper(c), ft_tolower(c));
	}
	printf("%s", "test done.\n");
}

static void		test_ft_memset(void)
{
	int			buffa[100];
	int			buffb[100];

	printf("%s", "testing ft_memset...\n");
	memset(buffa, 0xfa, sizeof(int) * 100);
	ft_memset(buffb, 0xfa, sizeof(int) * 100);
	printf("test0: %s\n",
			(memcmp(buffa, buffb, sizeof(int) * 100)) ? "Failed" : "Success");
}

static int		is_zero(const void *ptr, const size_t size)
{
	size_t		p;

	p = 0;
	while ((p < size) &&  (((char*)ptr)[p] == 0))
		p++;
	return (p != size);
}

static void		test_ft_bzero(void)
{
	char		test[100];
	char		actual[100];

	printf("%s", "testing ft_bzero...\n");
	ft_bzero(test, 100);
	bzero(actual, 100);
	printf("ft_bzero: %s\n", (is_zero(test, 100) ? "Failed" : "Success"));
}

static void		test_ft_strlen(void)
{
	const char *s = "This is the string to test.";
	size_t mine;
	size_t theirs;

	printf("%s", "testing ft_strlen...\n");
	mine = ft_strlen(s);
	theirs = strlen(s);
	printf("ft_strlen: %s\n", (mine == theirs) ? "Success" : "Failed");
}

int				main(void)
{
	test_isall();
	test_ft_memset();
	test_ft_bzero();
	test_ft_strlen();
	return (0);
}