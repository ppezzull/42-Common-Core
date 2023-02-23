# include "minitalk.h"

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int exponent = atoi(argv[2]);
	int n2 = n;

	if (exponent == 0)
	{
		printf("1\n");
	}
	exponent--;
	while (exponent)
	{
		n2 *= n;
		exponent--;
	}
	printf("%i\n", n2);	
}