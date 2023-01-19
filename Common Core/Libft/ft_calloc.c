#include "libft.h"

void    *ft_calloc(size_t nitems, size_t size)
{
    void    *out;
    size_t  i;

    out = malloc(nitems * size);
    if (!out)
        return (NULL);
    i = 0;
    while (i < nitems)
    {
        ((int *)out)[i] = 0;
        i++;
    }
    return (out);
}
