/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:46:22 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:46:23 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute(t_data *d, char *line)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		if (equal(line, op_name(i)))
		{
			op(d, i);
			return ;
		}
	}
	fail(d);
}

static void	read_ops(t_data *d)
{
	char	line[4];
	char	c;
	int		len;
	ssize_t	result;

	len = 0;
	result = read(0, &c, 1);
	while (result > 0)
	{
		if (c == '\n')
		{
			line[len] = 0;
			execute(d, line);
			len = 0;
		}
		else if (len == 3 || c == 0)
			fail(d);
		else
			line[len++] = c;
		result = read(0, &c, 1);
	}
	if (result < 0 || len)
		fail(d);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc == 1)
		return (0);
	d = (t_data){0};
	d.silent = 1;
	parse(&d, argc, argv);
	rank_input(&d);
	read_ops(&d);
	if (!d.b.n && sorted(&d.a))
		putstr(1, "OK\n");
	else
		putstr(1, "KO\n");
	destroy(&d);
	return (0);
}
