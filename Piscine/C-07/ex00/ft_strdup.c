#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
    char *copy;
    int len;
    int i;

    len = ft_strlen(src);
    copy = malloc(len * sizeof(char));
    i = 0;
    while (i < len)
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

int main()
{
    char *str = "Helloworld";
    char *result;
    // result = strdup(str);
    result = ft_strdup(str);
    printf("The string : %s", result);
    return 0;
}