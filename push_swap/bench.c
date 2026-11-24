/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:46:54 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:46:56 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	strategy(t_data *d, int selected)
{
	putstr(2, "[bench] strategy: ");
	if (d->mode == -1 || d->mode == 3)
		putstr(2, "Adaptive / ");
	else if (selected == 0)
		putstr(2, "Simple / ");
	else if (selected == 1)
		putstr(2, "Medium / ");
	else
		putstr(2, "Complex / ");
	if (selected == 0)
		putstr(2, "O(n^2)\n");
	else if (selected == 1)
		putstr(2, "O(n√n)\n");
	else
		putstr(2, "O(n log n)\n");
}

static void	operation_counts(t_data *d)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (i == 0 || i == 5)
			putstr(2, "[bench] ");
		else
			putstr(2, "  ");
		putstr(2, op_name(i));
		putstr(2, ": ");
		putnum(2, d->counts[i]);
		if (i == 4 || i == 10)
			putstr(2, "\n");
		i++;
	}
}

void	benchmark(t_data *d, int selected)
{
	size_t	total;
	int		i;
	int		percent;

	percent = (int)(d->disorder * 10000 + 0.5);
	putstr(2, "[bench] disorder: ");
	putnum(2, percent / 100);
	putstr(2, ".");
	if (percent % 100 < 10)
		putstr(2, "0");
	putnum(2, percent % 100);
	putstr(2, "%\n");
	strategy(d, selected);
	total = 0;
	i = -1;
	while (++i < 11)
		total += d->counts[i];
	putstr(2, "[bench] total_ops: ");
	putnum(2, total);
	putstr(2, "\n");
	operation_counts(d);
}
