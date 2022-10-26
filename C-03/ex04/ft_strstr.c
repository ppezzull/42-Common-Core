#include <string.h>
#include <stdio.h>

int is_found(char *str,char *to_find, int i)
{
    int j;

    j = 0;
    while (to_find[j] != 0)
    {
        if (to_find[j] != str[i])
            return (0);
        i++;
        j++;
    }
    return (1);
}

void    append_str(char *str, char *to_find)
{

}

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int found;

    i = 0;
    found = 0;
    while (str[i])
    {
        if (str[i] == to_find[0])
        {
            found = is_found(str, to_find, i);
            if (found)

                return (to_find);
        }
        i++;
    }
    return (0);
}

int main () {
    char haystack[] = "TutorialsPointblablabla";
    char needle[10] = "Point";
    char *ret;

    ret = strstr(haystack, needle);
    printf("strstr: %s\n", ret);

    ret = ft_strstr(haystack, needle);
    printf("ft_strstr: %s\n", ret);
    
    return(0);
}