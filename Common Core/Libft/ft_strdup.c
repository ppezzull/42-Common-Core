#include "libft.h"

char    *ft_strdup(const char *src)
{
    char *copy;
    int len;
    int i;

    len = ft_strlen(src);
    copy = malloc(len * sizeof(char));
    i = 0;
    while (i < len)
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}
