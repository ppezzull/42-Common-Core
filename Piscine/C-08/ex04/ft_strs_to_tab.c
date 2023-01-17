#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_strcpy(char *str)
{
    int     i;
    int     len;
    char    *copy;

    len = ft_strlen(str);
    copy = malloc(len * sizeof(char));
    if (!copy)
        return NULL;
    i = 0;
    while (i < len)
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    struct s_stock_str  *tab;
    struct s_stock_str  stock;
    int                 i;
    char                *str;

    tab = malloc(ac * sizeof(struct  s_stock_str));
    if (!tab)
        return NULL;
    i = 0;
    while (i < ac)
    {
        str = av[i];
        stock.size = ft_strlen(str);
        stock.str = str;
        stock.copy = ft_strcpy(str);
        tab[i] = stock;
        i++;
    }
    
    return tab;
}