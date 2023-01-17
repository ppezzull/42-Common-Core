#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memmove(void *str1, const void *str2, int n);

int main (int argc, char** argv)
{
   	char	*src;
	char	*dest;
	char	*dest2;
	int		n;

	if(argc == 4)
	{
   		dest = argv[1];
   		dest2 = argv[1];
   		src = argv[2];
		n = atoi(argv[3]);
   		printf("Before memcpy dest = %s\n", dest);
   		memmove(dest, src, n);
   		printf("memmove dest = %s\n", dest);
		// ft_memmove(dest2, src, n);
   		// printf("ft_memmove dest = %s\n", dest2);
	}
}