#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putnbr_base(unsigned long n, char *base, int len);
int	ft_print_pointer(void *ptr);

#endif