/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:21:27 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:28:20 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
