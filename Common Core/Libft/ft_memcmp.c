#include "libft.h"

int     ft_memcmp(const void *str1, const void *str2, size_t n)
{
    const char    *s1;
    const char    *s2;
 
    s1 = (const char *)str1;
    s2 = (const char *)str2;
    return (ft_strncmp(s1, s2, n));
}
