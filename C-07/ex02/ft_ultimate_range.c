#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int size;
    int *range2;
    int *buffer;
    int i;
    
    if( min >= max)
    {
        *range = 0;
        return (0);
    }
    size = max - min;
    range2 = (buffer = malloc(size * sizeof(int)));
    if (!range2)
    {
        *range = 0;
        return (-1);
    }
    *range = buffer;
    i = 0;
    while (i < size)
    {
        buffer[i] = i + min + 1;
        i++;
    }
    buffer[i] = '\0';
    return(size);
}

int main()
{
    int *range;
    int out;

    out = ft_ultimate_range(&range, 3, 9);
    printf("%d\n", out);
    for (int i = 0; range[i]; i++)
        printf("%d ", range[i]);

}