#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	total;

	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	total = count * size;
	pointer = malloc(total);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, total);
	return (pointer);
}