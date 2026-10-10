#include "ft_printf.h"
#include "libft/libft.h"

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
			ft_putnbr_fd(value, 1);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(args);
	return(0);
}

int	main(void)
{
	ft_printf("age = %d T_T\n", 39);
	ft_printf("A=%d B=%d\n", 10, 20);
	return (0);
}