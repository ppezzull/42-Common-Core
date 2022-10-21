#include <stdio.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        if (dest[i] != '\0')
        {
            dest[i] = src[i];
        }
        i++;
    }
    // if (src > dest)
    // {
    //     while (dest[i])
    //     {
    //         dest[i] = '\0';
    //         i++;
    //     }
    // }
    // else
    // {
    //     while (dest[i])
    //     {
    //         dest[i] = '\0';
    //         i++;
    //     }
    // }
    
    // printf("%c\n", dest[i]);
}

int main()
{
    char str1[]="bella frero come va";
    char str2[20];

    ft_strcpy(str2, str1);
    printf("%s \n", str1);
    printf("%s", str2);
}