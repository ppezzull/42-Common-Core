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

#include <unistd.h>

// void    ft_putchar(char c)
// {
//     write(1, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	int i;

//     i = 0;
//     while (str[i])
//     {
//         write(1, &str[i], 1);
//         i++;
//     }
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb >= 0)
// 	{
// 		if (nb <= 9)
// 			ft_putchar(nb + '0');
// 		else
// 		{
// 			ft_putnbr(nb / 10);
// 			ft_putchar(nb % 10 + '0');
// 		}
// 	}
// 	else
// 	{
// 		if (nb == -2147483648)
// 			write(1, "-2147483648", 11);
// 		else
// 		{
// 			write(1, "-", 1);
// 			ft_putnbr(nb * -1);
// 		}
// 	}
// }

// void ft_show_tab(struct s_stock_str *par)
// {
//     int i;

//     i = 0;
//     while (par[i].str != 0)
//     {
//         ft_putstr(par[i].str);
//         write(1, "\n", 1);
//         ft_putnbr(par[i].size);
//         write(1, "\n", 1);
//         ft_putstr(par[i].copy);
//         write(1, "\n", 1);
//         i++;
//     }
// }

int main(int ac, char **av) 
{
    struct s_stock_str  *tab;
    struct s_stock_str  stock;
    int                 i;

    tab = ft_strs_to_tab(ac, av);
    for (i = 0; i < ac; i++)
    {
        stock = tab[i];
        printf("%i %s %s\n", stock.size, stock.str, stock.copy);
    }
    // ft_show_tab(tab);
}