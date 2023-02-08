#include "get_next_line.h"

int main(int argc, char **argv)
{
    int 	fd;
	char 	*line;
    int		i;
	int		n = atoi(argv[1]);
    
	fd = open("lorem.txt", O_RDONLY);
	for(i = 0; i < n; i++)
		printf("%s\n", get_next_line(fd));
	close(fd);
	// printf("%s\n", ft_strjoin("ciao bello", "come va"));
}
