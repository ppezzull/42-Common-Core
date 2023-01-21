#include "libft.h"

void *ft_memset(void *ptr, int x, size_t n)
{
    char    *str;


    int     i;
    
    str = ptr;
    i = 0;
    while (n--)
    {
        str[i] = (unsigned char)x;
        i++;
    }
    return (ptr);
}