#include <stdio.h>
#include <string.h>

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

// int main()
// {
//     char stra1[] = "This is ";
//     char stra2[] = "programiz.com";
//     // strcat(stra1,stra2);
//     ft_strcat(stra1,stra2);
//     printf("%s", stra1);
//     return 0;
// }