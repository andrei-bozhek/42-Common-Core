/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:21:29 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:28:23 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_forward(unsigned char *dst,
		const unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	ft_copy_backward(unsigned char *dst,
		const unsigned char *src, size_t len)
{
	while (len > 0)
	{
		len--;
		dst[len] = src[len];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (dst == src || len == 0)
		return (dst);
	destination = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (destination < source)
		ft_copy_forward(destination, source, len);
	else
		ft_copy_backward(destination, source, len);
	return (dst);
}
