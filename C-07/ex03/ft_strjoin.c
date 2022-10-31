#include <stdio.h>
#include <stdlib.h>

int ft_strslen(int size, char **strs, char *sep)
{
    int i;
    int j;
    int len;

    i = 0;
    len = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
            j++;
        len += j;
        i++;
    }
    i = 0;
    while (sep[i] != '\0')
        i++;
    len += i * (size - 1);
    return (len);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int j;
    int k;
    int len;
    char *str;

    if (size == 0)
        return(NULL);
    len = ft_strslen(size, strs, sep);
    str = malloc(len * sizeof(char));
    i = 0;
    k = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
        {
            str[k] = strs[i][j];
            j++;
            k++;
        }
        if (i != size - 1)
        {
            j = 0;
            while (sep[j] != '\0')
            {
                str[k] = sep[j];
                k++;
                j++;
            }
        }
        i++;
    }
    return(str);
}

int main()
{   
    char *str;
    char *lst_str[3] = {"bella", "fratm", "bell"};

    str = ft_strjoin(3, lst_str, " ");
    free(str);
    printf("%s", str);
}