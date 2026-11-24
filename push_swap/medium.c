/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-17 08:55:40 by abozhek           #+#    #+#             */
/*   Updated: 2026-11-17 08:55:40 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	chunk(t_data *d, int low, int high)
{
	int	left;

	left = high - low;
	while (left--)
	{
		while (at(&d->a, 0) < low || at(&d->a, 0) >= high)
			op(d, RA);
		op(d, PB);
		if (at(&d->b, 0) < (low + high) / 2)
			op(d, RB);
	}
}

static void	return_chunks(t_data *d)
{
	int	i;
	int	max;

	while (d->b.n)
	{
		max = 0;
		i = 0;
		while (++i < d->b.n)
			if (at(&d->b, i) > at(&d->b, max))
				max = i;
		to_top(d, max, 1);
		op(d, PA);
	}
}

void	sort_medium(t_data *d)
{
	int	width;
	int	n;
	int	low;
	int	i;

	n = d->a.n;
	width = 1;
	while (width * width < n && width < 46340)
		width++;
	low = 0;
	while (low < n)
	{
		i = low + width;
		if (i > n)
			i = n;
		chunk(d, low, i);
		low = i;
	}
	return_chunks(d);
}
