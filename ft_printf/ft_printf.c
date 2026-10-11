#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return(write(fd, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static void	ft_putnbr_base(unsigned long n, char *base, int len)
{
	if (n >= (unsigned long)len)
		ft_putnbr_base(n / len, base, len);
	ft_putchar_fd(base[n % len], 1);
}

static int	ft_base_numlen(unsigned long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
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
			ft_putnbr_base(un_int_value, "0123456789abcdef", 16);
			count += ft_base_numlen(un_int_value, 16);
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
			ft_putnbr_base(un_int_value, "0123456789ABCDEF", 16);
			count += ft_base_numlen(un_int_value, 16);
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
				ft_putstr_fd("0x", 1);
				count += 2;
				ft_putnbr_base((unsigned long)pointer, "0123456789abcdef", 16);
				count += ft_base_numlen((unsigned long)pointer, 16);
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
	count = ft_printf("%x\n", 4294967295);
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