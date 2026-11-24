/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-17 08:55:20 by abozhek           #+#    #+#             */
/*   Updated: 2026-11-17 08:55:20 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*v;
	int	n;
	int	head;
	int	cap;
}	t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	int		mode;
	int		bench;
	int		silent;
	double	disorder;
	size_t	counts[11];
}	t_data;

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

int		at(t_stack *s, int i);
void	op(t_data *d, int code);
char	*op_name(int code);
void	putstr(int fd, const char *s);
void	putnum(int fd, size_t n);
void	fail(t_data *d);
void	destroy(t_data *d);
int		equal(const char *a, const char *b);
void	parse(t_data *d, int argc, char **argv);
void	rank_input(t_data *d);
int		sorted(t_stack *s);
void	sort_simple(t_data *d);
void	sort_medium(t_data *d);
void	sort_complex(t_data *d);
void	sort_small(t_data *d);
void	to_top(t_data *d, int pos, int stack_b);
void	benchmark(t_data *d, int selected);

#endif
