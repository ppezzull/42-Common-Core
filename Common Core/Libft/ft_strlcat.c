#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if ((int)size <= (int)ft_strlen(dest))
		return (size + ft_strlen((char *)src));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && i < size -1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&((char *)src)[j]));
}