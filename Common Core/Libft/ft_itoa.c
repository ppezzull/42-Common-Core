#include "libft.h"

int get_len(int n)
{
    int len;

    len = 0;
    if (n < 0)
    {
        len++;
        n *= -1;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char n_to_char(int n, int i)
{
    int     j;
    char    c;

    j = 0;
    while (j < i)
    {
        n = (n - (n % 10)) / 10;
        j++;
    }
    c = (n % 10) + '0';
    return (c);
}

char    *ft_itoa(int n)
{
    int     i;
    int     len;
    char    *str;

    if (n == 0)
        return ("0");
    len = get_len(n);
    str = malloc(len * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    if (n < 0)
    {
        str[i] = '-';
        n *= -1;
        i++;
    }
    while (i < len)
    {
        str[i] = n_to_char(n, len - i - 1);
        i++;
    }
    str[i] = '\0';
    return (str);
}