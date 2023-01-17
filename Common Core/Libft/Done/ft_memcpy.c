#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* ft_memcpy(void *dest, const void * src, int n)
{
	char*	destination;
	char*	source;
	int		i;

	i = 0;
	destination = dest;
	source = (void *)src;
	while (i < n && destination[i] != '\0' && source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	if(i-1 == n)
		destination[i] = '\0';
}

// int main (int argc, char** argv)
// {
//    	char	*src;
// 	char	*dest;
// 	char	*dest2;
// 	int		n;
// 
// 	if(argc == 4)
// 	{
//    		dest = argv[1];
//    		dest2 = argv[1];
//    		src = argv[2];
// 		n = atoi(argv[3]);
//    		printf("Before memcpy dest = %s\n", dest);
//    		memcpy(dest, src, n);
//    		printf("memcpy dest = %s\n", dest);
// 		ft_memcpy(dest2, src, n);
//    		printf("ft_memcpy dest = %s\n", dest2);
// 	}
// }