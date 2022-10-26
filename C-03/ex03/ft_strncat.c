#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    unsigned int j;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0' && j < nb)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int main()
{
   char src[] = "efghijkl";
   char dest[]= "abcd";
  
   // Appends 5 character from src to dest
//    strncat(dest, src, 5);
   ft_strncat(dest, src, 5);
   printf("%s", dest);
    
   return 0;
}