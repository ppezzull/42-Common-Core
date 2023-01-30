#include "libft.h"

int main(int argc, char **argv)
{
    int     n;
    char    letter;
    char    *word;
    char    *word2;
    // char    *src;
    char    **lst;
	(void)argc;
	(void)argv;

    word = "coucou";
	char src[] = "coucou";
	char dest[10]; memset(dest, 'A', 10);
    // src = argv[2];
    // letter = argv[2][0];
    n = atoi(argv[3]);
    printf("%zu\n", ft_strlcpy(dest,src,6));
	// printf("%zu\n", strlcpy(dest,src,6));
	printf("dest: %s\n", dest);
}