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

int	ft_putunbr_fd(unsigned int n, int fd)
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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int				i;
	int				int_value;
	char			*str_value;		
	unsigned int	un_int_value;
	void			*pointer;
	int				count;
	int				result;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && ( format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int_value = va_arg(args, int);
			result = ft_putnbr_fd(int_value, 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			un_int_value = va_arg(args, unsigned int);
			result = ft_putunbr_fd(un_int_value, 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			un_int_value = va_arg(args, unsigned int);
			result = ft_putnbr_base(un_int_value, "0123456789abcdef", 16);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			un_int_value = va_arg(args, unsigned int);
			result = ft_putnbr_base(un_int_value, "0123456789ABCDEF", 16);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			pointer = va_arg(args, void *);
			if (pointer == NULL)
			{
				result = ft_putstr_fd("(nil)", 1);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
			}
			else
			{
				result = ft_putstr_fd("0x", 1);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
				result = ft_putnbr_base((unsigned long)pointer, "0123456789abcdef", 16);
				if (result == -1)
				{
					va_end(args);
					return (-1);
				}
				count += result;
			}
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == 'c')
		{
			int_value = va_arg(args, int);
			result = ft_putchar_fd(int_value, 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == 's')
		{
			str_value = va_arg(args, char*);
			if (str_value == NULL)
				str_value = "(null)";
			result = ft_putstr_fd(str_value, 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == '%')
		{
			result = ft_putchar_fd('%', 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i += 2;
		}
		else
		{
			result = ft_putchar_fd(format[i], 1);
			if (result == -1)
			{
				va_end(args);
				return (-1);
			}
			count += result;
			i++;
		}
	}
	va_end(args);
	return (count);
}
