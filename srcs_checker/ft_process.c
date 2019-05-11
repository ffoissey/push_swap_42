/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:53:56 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 10:55:19 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_swap_long(long *nb1, long *nb2)
{
	long tmp;

	tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

int			ft_exec_swap(t_stack *s, char *str)
{
	if (ft_strequ(str, "sa"))
	{
		if (s->size_a > 1)
			ft_swap_long(&s->a[s->size_a - 1], &s->a[s->size_a - 2]);
	}
	else if (ft_strequ(str, "sb"))
	{
		if (s->size_b > 1)
			ft_swap_long(&s->b[s->size_b - 1], &s->b[s->size_b - 2]);
	}
	else if (ft_strequ(str, "ss"))
	{
		if (s->size_a > 1)
			ft_swap_long(&s->a[s->size_a - 1], &s->a[s->size_a - 2]);
		if (s->size_b > 1)
			ft_swap_long(&s->b[s->size_b - 1], &s->b[s->size_b - 2]);
	}
	else
		return (FALSE);
	return (TRUE);
}

int			ft_exec_push(t_stack *s, char *str)
{
	if (ft_strequ(str, "pa"))
	{
		if (s->size_b)
		{
			s->size_a++;
			s->a[s->size_a - 1] = s->b[s->size_b - 1];
			s->size_b--;
		}
	}
	else if (ft_strequ(str, "pb"))
	{
		if (s->size_a)
		{
			s->size_b++;
			s->b[s->size_b - 1] = s->a[s->size_a - 1];
			s->size_a--;
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

static void	ft_rotate_extend(long *tab, size_t size, int inc)
{
	size_t	i;
	long	tmp;

	if (size < 2)
		return ;
	if (inc > 0)
	{
		i = -1;
		tmp = tab[0];
		tab[0] = tab[size - 1];
		while (size - 1 - ++i > 0)
			tab[size - 1 - i] = tab[size - 2 - i];
		tab[1] = tmp;
	}
	else
	{
		i = -1;
		tmp = tab[size - 1];
		tab[size - 1] = tab[0];
		while (++i + 1 < size)
			tab[i] = tab[i + 1];
		tab[size - 2] = tmp;
	}
}

int			ft_exec_rotate(t_stack *s, char *str)
{
	if (ft_strequ(str, "ra"))
		ft_rotate_extend(s->a, s->size_a, 1);
	else if (ft_strequ(str, "rb"))
		ft_rotate_extend(s->b, s->size_b, 1);
	else if (ft_strequ(str, "rr"))
	{
		ft_rotate_extend(s->a, s->size_a, 1);
		ft_rotate_extend(s->b, s->size_b, 1);
	}
	else if (ft_strequ(str, "rra"))
		ft_rotate_extend(s->a, s->size_a, -1);
	else if (ft_strequ(str, "rrb"))
		ft_rotate_extend(s->b, s->size_b, -1);
	else if (ft_strequ(str, "rrr"))
	{
		ft_rotate_extend(s->a, s->size_a, -1);
		ft_rotate_extend(s->b, s->size_b, -1);
	}
	else
		return (FALSE);
	return (TRUE);
}
