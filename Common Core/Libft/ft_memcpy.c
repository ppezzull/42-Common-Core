#include "libft.h"

void *ft_memcpy(void *dest, const void * src, size_t n)
{
    char    *d;
    char    *s;
    size_t     i;

    d = (char *)dest;
    s = (char *)src;
    i = 0;
    while (n-- && s[i] != '\0')
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}