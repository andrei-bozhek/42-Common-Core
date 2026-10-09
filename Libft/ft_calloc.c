/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:20:27 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:27:49 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
