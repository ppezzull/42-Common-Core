#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    if (nb < 0 && power == 0)
        return (-1);
    if (power < 0)
        return (0);
    if (nb == 0 && power == 0 || power == 0)
        return (1);
    if (power > 1)
        return (nb * ft_recursive_power(nb, --power));
    return (nb);
}

int main()
{
    printf("res: %i", ft_recursive_power(4, 2));
}