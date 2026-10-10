/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:21:49 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:28:25 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
