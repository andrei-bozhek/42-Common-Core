#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		value;

	va_start(args, format);
	i = 0;
	while(format[i])
	{
		if (format[i] == '%' && format[i+1] == 'd')
		{
			value = va_arg(args, int);
			printf("%d", value);
			i += 2;
		}
		else
		{
			putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return(0);
}

int	main(void)
{
	ft_printf("age = %d T_T\n", 39);
	return (0);
}