#include "get_next_line.h"

int main()
{
    int 	fd;
	char 	*line;
    
    fd = open("lorem.txt", O_RDONLY);
    line = get_next_line(fd);

}