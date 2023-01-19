#include "libft.h"

char *ft_strrchr(const char *str, int ch)
{
    int     i;

    i = ft_strlen((char *)str) - 1;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
            return (&((char *)str)[i]);
        i--;
    }
    return (NULL);    
}