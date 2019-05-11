/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:09:51 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:30:39 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_over_pivot(long *tab, size_t size, long pivot, int which)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		if ((!which && tab[i] < pivot) || (which && tab[i] >= pivot))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	ft_three_a_extend(t_stack *s)
{
	if (ft_is_the_biggest(s->a, s->size_a, s->a[s->size_a - 1])
			&& !ft_is_the_smallest(s->a, s->size_a, s->a[s->size_a - 2]))
	{
		ft_cmd(ft_exec_swap, s, "sa");
		ft_cmd(ft_exec_rotate, s, "rra");
	}
	else if (ft_is_the_biggest(s->a, s->size_a, s->a[s->size_a - 1])
			&& ft_is_the_smallest(s->a, s->size_a, s->a[s->size_a - 2]))
		ft_cmd(ft_exec_rotate, s, "ra");
	else if (ft_is_the_smallest(s->a, s->size_a, s->a[s->size_a - 1])
			&& ft_is_the_biggest(s->a, s->size_a, s->a[s->size_a - 2]))
	{
		ft_cmd(ft_exec_rotate, s, "rra");
		ft_cmd(ft_exec_swap, s, "sa");
	}
	else if (!ft_is_the_smallest(s->a, s->size_a, s->a[s->size_a - 1])
			&& ft_is_the_biggest(s->a, s->size_a, s->a[0]))
		ft_cmd(ft_exec_swap, s, "sa");
	else
		ft_cmd(ft_exec_rotate, s, "rra");
}

void		ft_three_a(t_stack *s)
{
	if (s->size_a <= 1 || ft_is_good(s->a, s->size_a, 0))
		return ;
	else if (s->size_a == 2)
	{
		if (s->a[s->size_a - 1] > s->a[s->size_a - 2])
			ft_cmd(ft_exec_swap, s, "sa");
	}
	else
		ft_three_a_extend(s);
}

static void	ft_three_b_extend(t_stack *s)
{
	if (ft_is_the_smallest(s->b, s->size_b, s->b[s->size_b - 1])
			&& !ft_is_the_biggest(s->b, s->size_b, s->b[s->size_b - 2]))
	{
		ft_cmd(ft_exec_swap, s, "sb");
		ft_cmd(ft_exec_rotate, s, "rrb");
	}
	else if (ft_is_the_smallest(s->b, s->size_b, s->b[s->size_b - 1])
			&& ft_is_the_biggest(s->b, s->size_b, s->b[s->size_b - 2]))
		ft_cmd(ft_exec_rotate, s, "rb");
	else if (ft_is_the_biggest(s->b, s->size_b, s->b[s->size_b - 1])
			&& ft_is_the_smallest(s->b, s->size_b, s->b[s->size_b - 2]))
	{
		ft_cmd(ft_exec_rotate, s, "rrb");
		ft_cmd(ft_exec_swap, s, "sb");
	}
	else if (!ft_is_the_biggest(s->b, s->size_b, s->b[s->size_b - 1])
			&& ft_is_the_smallest(s->b, s->size_b, s->b[0]))
		ft_cmd(ft_exec_swap, s, "sb");
	else
		ft_cmd(ft_exec_rotate, s, "rrb");
}

void		ft_three_b(t_stack *s)
{
	if (s->size_b <= 1 || ft_is_good(s->b, s->size_b, 1))
		return ;
	else if (s->size_b == 2)
	{
		if (s->b[s->size_b - 1] < s->b[s->size_b - 2])
			ft_cmd(ft_exec_swap, s, "sb");
	}
	else
		ft_three_b_extend(s);
}
