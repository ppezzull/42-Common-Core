#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    int out;
    
    if (nb < 0)
        return (0);
    if (nb > 1)
        return (nb * ft_recursive_factorial(nb - 1));
}

int main()
{
    printf("res: %i", ft_recursive_factorial(10));
}