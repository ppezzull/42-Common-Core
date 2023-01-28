#include "libft.h"

int main(int argc, char **argv)
{
    int     n;
    char    letter;
    char    *word;
    char    *word2;
    char    *src;
    char    **lst;

    word = argv[1];
    word2 = argv[2];
    // src = argv[2];
    // letter = argv[2][0];
    // n = atoi(argv[3]);
    printf("%s\n", ft_strtrim(word, word2));
}