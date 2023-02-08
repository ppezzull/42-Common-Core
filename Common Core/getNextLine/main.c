#include "get_next_line.h"

int main(int argc, char **argv)
{
    int 	fd;
    int		i;
	int		n = atoi(argv[1]);
    
	fd = open("lorem.txt", O_RDONLY);
	for(i = 0; i < n; i++)
		printf("%s", get_next_line(fd));
	close(fd);
}
