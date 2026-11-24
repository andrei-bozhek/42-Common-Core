/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtakhiro <gtakhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:45:22 by gtakhiro          #+#    #+#             */
/*   Updated: 2026/11/17 17:45:27 by gtakhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	at(t_stack *s, int i)
{
	return (s->v[(s->head + i) % s->cap]);
}

static void	swap(t_stack *s)
{
	int	tmp;
	int	next;

	if (s->n < 2)
		return ;
	next = (s->head + 1) % s->cap;
	tmp = s->v[s->head];
	s->v[s->head] = s->v[next];
	s->v[next] = tmp;
}

static void	push(t_stack *dst, t_stack *src)
{
	if (!src->n)
		return ;
	dst->head = (dst->head + dst->cap - 1) % dst->cap;
	dst->v[dst->head] = at(src, 0);
	dst->n++;
	src->head = (src->head + 1) % src->cap;
	src->n--;
}

static void	rotate(t_stack *s, int reverse)
{
	int	tmp;

	if (s->n < 2)
		return ;
	if (reverse)
	{
		tmp = at(s, s->n - 1);
		s->head = (s->head + s->cap - 1) % s->cap;
		s->v[s->head] = tmp;
	}
	else
	{
		tmp = at(s, 0);
		s->v[(s->head + s->n) % s->cap] = tmp;
		s->head = (s->head + 1) % s->cap;
	}
}

void	op(t_data *d, int c)
{
	if (c == SA || c == SS)
		swap(&d->a);
	if (c == SB || c == SS)
		swap(&d->b);
	if (c == PA)
		push(&d->a, &d->b);
	if (c == PB)
		push(&d->b, &d->a);
	if (c == RA || c == RR || c == RRA || c == RRR)
		rotate(&d->a, c == RRA || c == RRR);
	if (c == RB || c == RR || c == RRB || c == RRR)
		rotate(&d->b, c == RRB || c == RRR);
	d->counts[c]++;
	if (!d->silent)
	{
		putstr(1, op_name(c));
		putstr(1, "\n");
	}
}
