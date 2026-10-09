/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:22:08 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:35:31 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*destination;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	destination = malloc(len + 1);
	if (!destination)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		destination[i] = s1[i];
		i++;
	}
	return (destination);
}
