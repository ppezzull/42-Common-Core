#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    int     len1;
    int     len2;
    int     i;
    char    *str;

    len1 = ft_strlen((char *)s1);
    len2 = ft_strlen((char *)s2);
    str = (char *)malloc((len1 + len2) * sizeof(char));
    i = 0;
    if (!str)
        return (NULL);
    while (i < len1)
    {
        str[i] = s1[i];
        i++;
    }
    while (i < len1 + len2)
    {
        str[i] = s2[i - len1];
        i++;
    }
    str[i] = '\0';
    return (str);
}
