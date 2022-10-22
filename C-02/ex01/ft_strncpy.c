char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int i;

    i = 0;
    while (i < n && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    while (dest[i])
    {
        dest[i] = '\0';
        i++;
    }
    return(dest);
}