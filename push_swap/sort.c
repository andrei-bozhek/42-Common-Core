/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:45:35 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:45:37 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (++i < s->n)
		if (at(s, i - 1) > at(s, i))
			return (0);
	return (1);
}

void	to_top(t_data *d, int pos, int stack_b)
{
	int	n;
	int	forward;
	int	backward;

	n = d->a.n;
	forward = RA;
	backward = RRA;
	if (stack_b)
	{
		n = d->b.n;
		forward = RB;
		backward = RRB;
	}
	if (pos <= n / 2)
		while (pos-- > 0)
			op(d, forward);
	else
		while (pos++ < n)
			op(d, backward);
}

void	sort_simple(t_data *d)
{
	int	i;
	int	min;

	while (d->a.n > 3 && !sorted(&d->a))
	{
		min = 0;
		i = 0;
		while (++i < d->a.n)
			if (at(&d->a, i) < at(&d->a, min))
				min = i;
		to_top(d, min, 0);
		op(d, PB);
	}
	sort_small(d);
	while (d->b.n)
		op(d, PA);
}

void	sort_small(t_data *d)
{
	int	max;
	int	i;

	if (sorted(&d->a))
		return ;
	if (d->a.n == 3)
	{
		max = 0;
		i = 0;
		while (++i < 3)
			if (at(&d->a, i) > at(&d->a, max))
				max = i;
		if (max == 0)
			op(d, RA);
		if (max == 1)
			op(d, RRA);
	}
	if (at(&d->a, 0) > at(&d->a, 1))
		op(d, SA);
}

void	sort_complex(t_data *d)
{
	int	bit;
	int	i;
	int	n;

	n = d->a.n;
	bit = 0;
	while (((n - 1) >> bit) && !sorted(&d->a))
	{
		i = 0;
		while (i++ < n)
		{
			if ((at(&d->a, 0) >> bit) & 1)
				op(d, RA);
			else
				op(d, PB);
		}
		while (d->b.n)
			op(d, PA);
		bit++;
	}
}
