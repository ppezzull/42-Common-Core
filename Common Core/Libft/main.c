#include "libft.h"

int main(int argc, char **argv)
{
    int     n;
    int     n2;
    char    letter;
    char    *word;
    char    *word2;

    // word = argv[1];
    // word2 = argv[2];
    // src = argv[2];
    // letter = argv[2][0];
    n = atoi(argv[1]);
    // n2 = atoi(argv[3]);
    printf("%s\n", ft_itoa(n));
}