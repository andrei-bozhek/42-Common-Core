#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*byte_sequence;

	byte_sequence = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		byte_sequence[i] = (unsigned char)c;
		i++;
	}
	return (s);
}