#include "get_next_line.h"

int main()
{
    int fd;
    
    fd = open("lorem.txt", O_RDONLY);
    get_next_line(fd);
}