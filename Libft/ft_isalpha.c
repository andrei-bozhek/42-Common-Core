#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return (1);
	return (0);
}
// #include <ctype.h>
// #include <stdio.h>
// int	main(void)
// {
// 	printf("ft: %d | original: %d\n", ft_isalpha('A'), isalpha('A'));
// 	printf("ft: %d | original: %d\n", ft_isalpha('z'), isalpha('z'));
// 	printf("ft: %d | original: %d\n", ft_isalpha('1'), isalpha('1'));
// 	printf("ft: %d | original: %d\n", ft_isalpha(10), isalpha(10));
// 	return (0);
// }