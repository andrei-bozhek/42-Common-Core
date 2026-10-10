#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_nbr_len(int nbr)
{
	int		len;
	long	n;

	n = nbr;
	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'd')
		{
			value = va_arg(args, int);
			ft_putnbr_fd(value, 1);
			count += ft_nbr_len(value);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{	
	int	count;

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
	count = ft_printf("");
	ft_printf("count = %d\n", count);
	return (0);
}