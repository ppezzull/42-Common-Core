#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    int     i;
    int     j;
    char    *substr;

    substr = (char *)malloc(len * sizeof(char));
    if (!substr)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (i >= start && j <= len)
        {
            substr[j] = s[i];
            j++;
        }
        i++;
    }
    substr[j] = '\0';
    return (substr);
}
