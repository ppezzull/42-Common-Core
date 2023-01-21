#include "libft.h"

void *ft_memmove(void *dest, const void * src, size_t n)
{
    char    *d;
    char    *s;
    size_t     i;

    d = (char *)dest;
    s = (char *)src;
    i = 0;
    if (src < dest) 
    {
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    } else {
        while (n--)
            d[n] = s[n];
    }
    return (dest);
}