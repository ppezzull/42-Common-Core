#include <stdio.h>

int ft_fibonacci(int index)
{
    int out;

    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index == 1)
        return (1);
    if (index > 1)
    {
        out = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
        return (out);
    }
 
}   

int main()
{
    printf("res: %i", ft_fibonacci(-32));
}