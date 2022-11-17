#ifndef HEADER_FILE
#define HEADER_FILE
#include <unistd.h>

typedef enum
{
    FALSE,
	TRUE,
}  t_bool;

#define TRUE            1
#define FALSE           0
#define SUCCESS         0
#define ODD_MSG         "I have an odd number of arguments.\n"
#define EVEN_MSG        "I have an even number of arguments.\n"
#define EVEN(n)         n % 2 == 0

#endif