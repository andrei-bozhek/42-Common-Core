#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_char;

	last_char = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_char = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_char);
}