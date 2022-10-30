#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int i;
    int num;
    
    i = 2;
    num = 1;
    if (nb < 0)
        return (0);
    while (i <= nb)
    {
        num *= i;
        i++;
    }
    return (num);
}

int main()
{
    printf ("%i",ft_iterative_factorial(2));
    return 0;
}
