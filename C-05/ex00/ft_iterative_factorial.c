/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int i;
    int num;
    
    i = 2;
    num = 1;
    while (i <= nb)
    {
        num *= i;
        i++;
    }
    return (num);
}

int main()
{
    printf ("%i",ft_iterative_factorial(0));

    return 0;
}
