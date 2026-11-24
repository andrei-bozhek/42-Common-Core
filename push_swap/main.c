/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:46:14 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:46:15 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	select_strategy(t_data *d)
{
	int	selected;

	selected = d->mode;
	if (selected == -1 || selected == 3)
	{
		selected = 2;
		if (d->disorder < 0.5)
			selected = 1;
		if (d->disorder < 0.2)
			selected = 0;
	}
	return (selected);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		selected;

	d = (t_data){0};
	d.mode = -1;
	if (argc == 1)
		return (0);
	parse(&d, argc, argv);
	rank_input(&d);
	selected = select_strategy(&d);
	if (!sorted(&d.a))
	{
		if (selected == 0 || d.a.n <= 5)
			sort_simple(&d);
		else if (selected == 1)
			sort_medium(&d);
		else
			sort_complex(&d);
	}
	if (d.bench)
		benchmark(&d, selected);
	destroy(&d);
	return (0);
}
