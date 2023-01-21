#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t n)
{
    size_t     i;
    char    *s;

    i = 0;
    s = (char *)str;
    while (s[i] != '\0' && i < n)
    {
        if (s[i] == c)
            return (&((char *)str)[i]);
        i++;
    }
    return (NULL);
}