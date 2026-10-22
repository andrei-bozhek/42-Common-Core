#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{	
	int count;
	int	result;
	
	count = 0;
	while (*s)
	{
		result = write(fd, s, 1);
		if (result != 1)
			return (-1);
		count += result;
		s++;
	}	
	return(count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		result;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		result = ft_putchar_fd('-', fd);
		if (result == -1)
			return (-1);
		nbr = -nbr;
		count += result;
	}
	if (nbr >= 10)
	{
		result = ft_putnbr_fd(nbr / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(nbr % 10 + '0', fd);
	if (result == -1)
		return (-1);
	return(result + count);
}

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	int count;
	int result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putunbr_fd(n / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(n % 10 + '0', fd);
	if (result == -1)
		return (-1);
	return(result + count);
}

static int	ft_putnbr_base(unsigned long n, char *base, int len)
{
	int	count;
	int result;

	count = 0;
	if (n >= (unsigned long)len)
	{
		result = ft_putnbr_base(n / len, base, len);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(base[n % len], 1);
	if (result == -1)
		return (-1);
	return(result + count);
}

static int	ft_print_pointer(void *ptr)
{
	int	count;
	int	result;

	if (ptr == NULL)
		return (ft_putstr_fd("(nil)", 1));
	count = ft_putstr_fd("0x", 1);
	if (count == -1)
		return (-1);
	result = ft_putnbr_base((unsigned long)ptr,
			"0123456789abcdef", 16);
	if (result == -1)
		return (-1);
	return (count + result);
}

static int	ft_print_string(char *s)
{
	if (s == NULL)
		s = "(null)";
	return (ft_putstr_fd(s, 1));
}

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
		return (ft_print_string(va_arg(*args, char *)));
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
