/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:22:31 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:36:19 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
