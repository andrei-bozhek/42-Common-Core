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

static int	ft_unbr_len(unsigned int n)
{
	int		len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

static int	ft_putnbr_base(unsigned long n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base, base_len);
	ft_putchar_fd(base[n % base_len], 1);
	return (count + 1);
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

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && ( format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int_value = va_arg(args, int);
			ft_putnbr_fd(int_value, 1);
			count += ft_nbr_len(int_value);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			un_int_value = va_arg(args, unsigned int);
			ft_putunbr_fd(un_int_value, 1);
			count += ft_unbr_len(un_int_value);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			un_int_value = va_arg(args, unsigned int);
			count += ft_putnbr_base(un_int_value, "0123456789abcdef", 16);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			un_int_value = va_arg(args, unsigned int);
			count += ft_putnbr_base(un_int_value, "0123456789ABCDEF", 16);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			pointer = va_arg(args, void*);
			if (pointer == NULL)
			{
				ft_putstr_fd("(nil)",1);
				count += 5;
			}
			else
			{
				ft_putstr_fd("0x", 1);
				count += 2;
				count += ft_putnbr_base((unsigned long)pointer, "0123456789abcdef", 16);
			}			
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == 'c')
		{
			int_value = va_arg(args, int);
			ft_putchar_fd(int_value, 1);
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == 's')
		{
			str_value = va_arg(args, char*);
			if (str_value == NULL)
				str_value = "(null)";
			ft_putstr_fd(str_value, 1);
			count += ft_strlen(str_value);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1]  == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
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