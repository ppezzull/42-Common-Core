#include "libft.h"

int     charset_len(char *s, char c, int i)
{
    if (s[i] == c)
        return (1 + charset_len(s, c, i + 1));
    return (0);
}

int     nWords(char *s, char c)
{
    int i;
    int words;
    int found;

    i = 0;
    words = 0;
    while (s[i] != '\0')
    {
        found = charset_len(s, c, i);
        if (found)
            i += found;
        else  
        {
            while (!charset_len(s, c, i) && s[i] != '\0')
                i++; 
            words++;
        }            
    }
    return words;
}

char    *getWord(char *str, int start, int end)
{
    int     len;
    int     i;
    char    *word;

    len = end - start;
    word = malloc(len * sizeof(char));
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char const *s, char c)
{
    char    **split;
    int     n_words;
    int     i;
    int     j;
    int     start;

    n_words = nWords((char *)s, c);
    split = malloc(n_words * sizeof(char));
    if (!split)
        return (NULL);
    i = 0;
    j = 0;
    while (i < n_words) 
    {
        j += charset_len((char *)s, c, j);  
        start = j;
        while (!charset_len((char *)s, c, j) && s[j] != '\0')
            j++;
        split[i] = getWord((char *)s, start, j);
        i++;
    }
    split[i] = '\0';
    return split;
}