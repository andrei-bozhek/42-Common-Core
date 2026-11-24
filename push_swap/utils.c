/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-17 08:55:55 by abozhek           #+#    #+#             */
/*   Updated: 2026-11-17 08:55:55 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(int fd, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (write(fd, s, i) < 0)
		return ;
}

void	putnum(int fd, size_t n)
{
	char	c;

	if (n > 9)
		putnum(fd, n / 10);
	c = '0' + n % 10;
	if (write(fd, &c, 1) < 0)
		return ;
}

int	equal(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == *b);
}

void	destroy(t_data *d)
{
	free(d->a.v);
	free(d->b.v);
}

void	fail(t_data *d)
{
	destroy(d);
	putstr(2, "Error\n");
	exit(1);
}
