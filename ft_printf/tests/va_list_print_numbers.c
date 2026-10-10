// va_list   → создать переменную для обхода аргументов
// va_start  → поставить её в начало списка
// va_arg    → взять следующий аргумент
// va_end    → закончить работу

#include <stdarg.h>
#include <stdio.h>

void	print_numbers(int count, ...)
{
	va_list	args;
	int		i;
	int		value;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		value = va_arg(args, int);
		printf("%d\n", value);
		i++;
	}
	va_end(args);
}

int	main(void)
{
	print_numbers(3, 10, 20, 30);
	return(0);
}