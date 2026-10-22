#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int len)
{
	int	count;
	int	result;

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
	return (result + count);
}

int	ft_print_pointer(void *ptr)
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
