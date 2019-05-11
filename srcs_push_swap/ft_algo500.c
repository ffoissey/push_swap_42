/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:01:08 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:23:27 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_loop_divide_b(t_stack *s, int *ret_a, int *ret_b, long pivot)
{
	if (s->size_a > 1 && s->a[s->size_a - 1] > s->a[s->size_a - 2])
		ft_cmd(ft_exec_swap, s, "sa");
	else if (s->b[s->size_b - 1] < s->b[s->size_b - 2]
			&& s->b[s->size_b - 1] >= pivot)
		ft_cmd(ft_exec_swap, s, "sb");
	else if (s->b[s->size_b - 1] >= pivot)
		ft_cmd(ft_exec_push, s, "pa");
	else
	{
		ft_cmd(ft_exec_rotate, s, "rb");
		if (s->size_a
				&& ft_is_the_biggest(s->a, s->size_a, s->a[s->size_a - 1]))
			ft_cmd(ft_exec_rotate, s, "ra");
	}
	ft_reposition(s, ret_a, ret_b, 1);
}

static void	ft_divide_b_stack500(t_stack *s, int *ret_a, int *ret_b)
{
	long	pivot;
	size_t	i;

	i = 1;
	if (s->size_b < 4)
		ft_three_b(s);
	ft_reposition(s, ret_a, ret_b, 0);
	if (s->size_b < 4 || *ret_b)
		return ;
	pivot = s->b[s->size_b - 1];
	while (s->size_b > i && s->b[s->size_b - i] < s->b[s->size_b - (i + 1)])
		pivot = s->b[s->size_b - ++i];
	while (s->size_b > 3 && ft_over_pivot(s->b, s->size_b, pivot, 1)
			&& !ft_is_good(s->b, s->size_b, 1))
		ft_loop_divide_b(s, ret_a, ret_b, pivot);
}

static void	ft_loop_divide_a(t_stack *s, int *ret_a, int *ret_b, long pivot)
{
	if (s->size_b > 1 && s->b[s->size_b - 1] < s->b[s->size_b - 2])
		ft_cmd(ft_exec_swap, s, "sb");
	else if (s->a[s->size_a - 1] > s->a[s->size_a - 2]
			&& s->a[s->size_a - 1] < pivot)
		ft_cmd(ft_exec_swap, s, "sa");
	else if (s->a[s->size_a - 1] < pivot)
		ft_cmd(ft_exec_push, s, "pb");
	else
	{
		ft_cmd(ft_exec_rotate, s, "ra");
		if (s->size_b
				&& ft_is_the_smallest(s->b, s->size_b, s->b[s->size_b - 1]))
			ft_cmd(ft_exec_rotate, s, "rb");
	}
	ft_reposition(s, ret_a, ret_b, 1);
}

static void	ft_divide_a_stack500(t_stack *s, int *ret_a, int *ret_b)
{
	long	pivot;

	if (s->size_a < 4)
		ft_three_a(s);
	ft_reposition(s, ret_a, ret_b, 0);
	if (s->size_a < 4 || *ret_a)
		return ;
	pivot = ft_med_stack(s->a, s->size_a);
	if (ft_is_the_smallest(s->a, s->size_a, pivot))
		return ;
	while (s->size_a > 3 && ft_over_pivot(s->a, s->size_a, pivot, 0)
			&& !ft_is_good(s->a, s->size_a, 0))
		ft_loop_divide_a(s, ret_a, ret_b, pivot);
	ft_divide_a_stack500(s, ret_a, ret_b);
}

int			ft_process_sort500(t_stack *s)
{
	int		ret_a;
	int		ret_b;

	if (s->size_a < 4)
		ft_three_a(s);
	while (!ft_reposition(s, &ret_a, &ret_b, 1))
	{
		ft_divide_b_stack500(s, &ret_a, &ret_b);
		ft_reposition(s, &ret_a, &ret_b, 0);
		ft_divide_a_stack500(s, &ret_a, &ret_b);
		ft_process_sort500(s);
	}
	while (s->size_b)
		ft_cmd(ft_exec_push, s, "pa");
	ft_reposition(s, &ret_a, &ret_b, 1);
	return (TRUE);
}
