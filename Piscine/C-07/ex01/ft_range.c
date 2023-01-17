#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int size;
    int *range;
    int i;
    
    if( min >= max)
        return (NULL);
    i = 0;
    size = max - min;
    range = malloc(size * sizeof(int));
    while (i < size)
    {
        range[i] = i + min;
        i++;
    }
    range[i] = '\0';
    return(range);
}

int main()
{
    int *range;
    range = ft_range(3, 9);
    for (int i = 0; range[i]; i++)
        printf("%i ", range[i]);
}
