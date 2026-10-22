#include "ft_printf.h"

static int	ft_print_conversion(char type, va_list *args)
{
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), 1));
	if (type == 'u')
		return (ft_putunbr_fd(va_arg(*args, unsigned int), 1));
	if (type == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef", 16));
	if (type == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16));
	if (type == 'p')
		return (ft_print_pointer(va_arg(*args, void *)));
	if (type == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (type == 's')
		return (ft_putstr_fd(va_arg(*args, char *), 1));
	if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (-1);
}

static int	ft_parse_format(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	result;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result = ft_print_conversion(format[i], args);
		}
		else
			result = ft_putchar_fd(format[i], 1);
		if (result == -1)
			return (-1);
		count += result;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_parse_format(format, &args);
	va_end(args);
	return (count);
}
