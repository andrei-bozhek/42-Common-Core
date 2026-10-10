#include <stdio.h>

int	main(void)
{
	int	count;

	count = printf("Hello %s! Number: %d\n", "42", 123);
	printf("Characters printed: %d\n", count);
	return (0);
}