#include "libft.h"

char	*ft_strnstr(const char * s1, const char * s2, size_t len)
{
	size_t	i;
	size_t	s2_len;

	if (!s1[0])
		return ((char *)s2);
	s2_len = ft_strlen(s1);
	i = 0;
	while (s2[i] && i <= len)
	{
		if (ft_strncmp(&s1[i], s2, s2_len))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}