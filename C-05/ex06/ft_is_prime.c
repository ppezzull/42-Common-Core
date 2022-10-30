#include <stdio.h>

int ft_is_prime(int nb)
{
    int i;
    
    i = 2;
    if (nb == 0 || nb == 1 || nb < 0)
        return (0);
    while (i < nb)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (ft_is_prime(i))
            printf("%i ", i);
    }
}