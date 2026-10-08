/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:21:22 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:28:16 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_pointer;
	size_t				i;

	s_pointer = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_pointer[i] == (unsigned char)c)
			return ((void *)(s_pointer + i));
		i++;
	}
	return (NULL);
}
