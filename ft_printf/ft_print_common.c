int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
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
	return (count);
}

static int	ft_print_string(char *s)
{
	if (s == NULL)
		s = "(null)";
	return (ft_putstr_fd(s, 1));
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
	return (result + count);
}

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;
	int	result;

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
	return (result + count);
}
