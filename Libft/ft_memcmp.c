#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_pointer;
	const unsigned char	*s2_pointer;
	size_t				i;

	s1_pointer = (const unsigned char *)s1;
	s2_pointer = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_pointer[i] != s2_pointer[i])
			return (s1_pointer[i] - s2_pointer[i]);
		i++;
	}
	return (0);
}