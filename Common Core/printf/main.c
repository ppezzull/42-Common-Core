#include "ft_printf.h"

int main()
{
    int len;
    
    len = ft_printf("%u\n", -3);
    printf("%u\n", -1);
    ft_printf("%i\n", len);
}