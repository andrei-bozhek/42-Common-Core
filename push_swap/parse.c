/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:45:57 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:45:59 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	number(t_data *d, char **p)
{
	long	n;
	int		sign;

	sign = 1;
	if (**p == '-' || **p == '+')
	{
		if (**p == '-')
			sign = -1;
		(*p)++;
	}
	if (**p < '0' || **p > '9')
		fail(d);
	n = 0;
	while (**p >= '0' && **p <= '9')
	{
		n = n * 10 + *(*p)++ - '0';
		if (n > (long)INT_MAX + (sign == -1))
			fail(d);
	}
	if (**p && !space(**p))
		fail(d);
	return ((int)(n * sign));
}

static int	flag(t_data *d, char *s)
{
	if (equal(s, "--bench") && !d->bench)
		d->bench = 1;
	else if (d->mode == -1 && equal(s, "--simple"))
		d->mode = 0;
	else if (d->mode == -1 && equal(s, "--medium"))
		d->mode = 1;
	else if (d->mode == -1 && equal(s, "--complex"))
		d->mode = 2;
	else if (d->mode == -1 && equal(s, "--adaptive"))
		d->mode = 3;
	else
		return (0);
	return (1);
}

static void	argument(t_data *d, char *s)
{
	int	before;

	before = d->a.n;
	while (*s)
	{
		while (space(*s))
			s++;
		if (*s)
			d->a.v[d->a.n++] = number(d, &s);
	}
	if (d->a.n == before)
		fail(d);
}

void	parse(t_data *d, int argc, char **argv)
{
	size_t	cap;
	int		i;
	int		j;

	cap = 0;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j++])
			cap++;
	}
	if (cap > INT_MAX - 1)
		fail(d);
	d->a.cap = (int)cap + 1;
	d->b.cap = d->a.cap;
	d->a.v = malloc(sizeof(int) * d->a.cap);
	d->b.v = malloc(sizeof(int) * d->b.cap);
	if (!d->a.v || !d->b.v)
		fail(d);
	i = 0;
	while (++i < argc)
		if (d->silent || !flag(d, argv[i]))
			argument(d, argv[i]);
}
