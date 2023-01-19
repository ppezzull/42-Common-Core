#include "libft.h"

void *ft_memmove(void *dest, const void * src, size_t n)
{
    char    *d;
    char    *s;
    int     i;

    d = (char *)dest;
    s = (char *)src;
    i = 0;
    if (src < dest) 
        ft_memcpy(dest, src, n);
    else
    {
        printf("porcamado\n");
        while (n--)
            d[n] = s[n];
    }
    return (dest);
}