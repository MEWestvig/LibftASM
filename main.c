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

	printf("%s", "Testing for ft_is*...\n");
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

	printf("%s", "Testing ft_memset...\n");
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

	printf("%s", "Testing ft_bzero...\n");
	ft_bzero(test, 100);
	bzero(actual, 100);
	printf("ft_bzero: %s\n", (is_zero(test, 100) ? "Failed" : "Success"));
}

static void		test_ft_strlen(void)
{
	const char *s = "This is the string to test.";
	size_t mine;
	size_t theirs;

	printf("%s", "Testing ft_strlen...\n");
	mine = ft_strlen(s);
	theirs = strlen(s);
	printf("ft_strlen: %s\n", (mine == theirs) ? "Success" : "Failed");
}

static void		test_ft_strcat(void)
{
	char buffer1[200];
	char buffer2[200];
	char *mine;
	char *theirs;

	printf("%s", "Testing ft_strcat...\n");
	buffer1[0] = '\0';
	mine = ft_strcat(buffer1, "Hello this is to test");
	printf("Mine: %s %s\n", buffer1, mine);
	buffer2[0] = '\0';
	theirs = strcat(buffer2, "Hello this is to test");
	printf("Theirs: %s %s\n", buffer2, theirs);
	printf("ft_strlen: %s\n", (strcmp(mine, theirs)) ? "Failed" : "Success");
}

static void		test_ft_memcpy(void)
{
	const char src[50] = "Testing this!";
	char dest[50];
	char *mine;
	char *theirs;

	printf("%s", "Testing ft_memcpy...\n");
	strcpy(dest,"Hello!");
	printf("Before memcpy dest = %s\n", dest);
	mine = ft_memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	strcpy(dest,"Hello!");
	theirs = memcpy(dest, src, strlen(src)+1);
	printf("ft_memcpy: %s\n", (memcmp(mine, theirs,strlen(src)+1)) ? "Failed" : "Success");
}

static void		test_ft_puts(void)
{
	const char test[50] = "Testing this!";

	printf("%s", "Testing ft_puts...\n");
	ft_puts(test);
	puts(test);
	printf("If it prints the same, Success!\n");
}

static void		test_ft_strdup(void)
{
	const char src[50] = "Testing this!";
	char *mine;
	char *theirs;

	printf("%s", "Testing ft_strdup...\n");
	mine = ft_strdup(src);
	printf("My strdup outputs = %s\n", mine);
	theirs = strdup(src);
	printf("Their strdup outputs = %s\n", theirs);
	printf("ft_strdup: %s\n", (memcmp(mine, theirs,strlen(src)+1)) ? "Failed" : "Success");
}

static void		test_ft_cat(void)
{
	int		fd;

	ft_puts("Testing ft_cat...");
	fd = open("cat_test.txt", O_RDONLY);
	if (fd < 0)
		return ;
	ft_cat(fd);
	close(fd);
	ft_puts("--------------------\n");
	ft_cat(STDIN_FILENO);
	ft_cat(-1);
}

int				main(void)
{
	test_isall();
	printf("\n");
	test_ft_memset();
	printf("\n");
	test_ft_bzero();
	printf("\n");
	test_ft_strlen();
	printf("\n");
	test_ft_strcat();
	printf("\n");
	test_ft_memcpy();
	printf("\n");
	test_ft_puts();
	printf("\n");
	test_ft_strdup();
	printf("\n");
	test_ft_cat();
	return (0);
}