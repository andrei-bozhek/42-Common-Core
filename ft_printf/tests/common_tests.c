#include "../printf.h"

int	main(void)
{	
	int	count;

	// %d
	count = ft_printf("age = %d T_T\n", 39);
	ft_printf("count = %d\n", count);
	count = ft_printf("A=%d B=%d\n", 10, 20);
	ft_printf("count = %d\n", count);
	count = ft_printf("%d\n", INT_MIN);
	ft_printf("count = %d\n", count);
	count = ft_printf("%d\n", -42);
	ft_printf("count = %d\n", count);
	count = ft_printf("%d\n", 42);
	ft_printf("count = %d\n", count);
	count = ft_printf("\n");
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %u
	count = ft_printf("%u\n", 0U);
	ft_printf("count = %d\n", count);
	count = ft_printf("%u\n", 42U);
	ft_printf("count = %d\n", count);
	count = ft_printf("%u\n", 2147483648U);
	ft_printf("count = %d\n", count);
	count = ft_printf("%u\n", UINT_MAX);
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %x
	count = ft_printf("%x\n", 0);
	ft_printf("count = %d\n", count);
	count = ft_printf("%x\n", 9);
	ft_printf("count = %d\n", count);
	count = ft_printf("%x\n", 10);
	ft_printf("count = %d\n", count);
	count = ft_printf("%x\n", 255);
	ft_printf("count = %d\n", count);
	count = ft_printf("%x\n", 256);
	ft_printf("count = %d\n", count);
	count = ft_printf("%x\n", UINT_MAX);
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %X
	count = ft_printf("%X\n", 0);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", 9);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", 10);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", 255);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", 256);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", 4294967295);
	ft_printf("count = %d\n", count);
	count = ft_printf("%X\n", UINT_MAX);
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %c
	count = ft_printf("%c\n", 'A');
	ft_printf("count = %d\n", count);
	count = ft_printf("%c\n", 'Z');
	ft_printf("count = %d\n", count);
	count = ft_printf("%c%c%c%c%c%c\n", 'A','B','C','D','E','F');
	ft_printf("count = %d\n", count);
	count = ft_printf("A%cB\n", '\0');
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %s
	count = ft_printf("Hello %s!\n", "42");
	ft_printf("count = %d\n", count);
	count = ft_printf("A%sB\n", "");
	ft_printf("count = %d\n", count);
	count = ft_printf("%s%s\n", "Hello", "World");
	ft_printf("count = %d\n", count);
	count = ft_printf("%s\n", (char *)NULL);
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	// %%
	count = ft_printf("50%%\n");
	ft_printf("count = %d\n", count);
	count = ft_printf("50%%%\n");
	ft_printf("count = %d\n", count);
	count = ft_printf("50%%%%\n");
	ft_printf("count = %d\n", count);
	ft_printf("\n");
	//%p comparsion
	int	n = 42;
	int	*ptr = &n;

	printf("Original: %p\n", (void *)ptr);
	ft_printf("Custom:   %p\n", (void *)ptr);
	printf("Original: %p\n", (void *)NULL);
	ft_printf("Custom:   %p\n", (void *)NULL);
	return (0);
}