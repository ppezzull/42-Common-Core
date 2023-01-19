#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    while(i < size && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    while (i < size)
    { 
        dst[i] = '\0';
        i++;
    }
    return ft_strlen(dst);
}
