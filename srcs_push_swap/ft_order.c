/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:02:37 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:49:24 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_good(long *tab, size_t size, int which)
{
	size_t		i;

	i = 0;
	while (i + 1 < size)
	{
		if ((which == 0 && tab[i] < tab[i + 1])
				|| (which == 1 && tab[i] > tab[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static long	*ft_dup_stack(long *tab, size_t size)
{
	long	*s;
	size_t	i;

	i = 0;
	if (!(s = (long *)malloc(sizeof(long) * size)))
		return (NULL);
	while (i < size)
	{
		s[i] = tab[i];
		i++;
	}
	return (s);
}

static int	ft_check_rotate(long *tab, size_t size, int which)
{
	size_t	i;
	t_stack	s;
	long	*tmp;

	s.size_a = which == 1 ? 0 : size;
	s.size_b = which == 0 ? 0 : size;
	if (!(tmp = ft_dup_stack(tab, size)))
		return (0);
	s.a = which == 1 ? NULL : tmp;
	s.b = which == 0 ? NULL : tmp;
	i = 0;
	while (i < size)
	{
		if (ft_is_good(tmp, size, which))
		{
			free(tmp);
			return (i ? (int)i : -1);
		}
		ft_exec_rotate(&s, which == 1 ? "rb" : "ra");
		i++;
	}
	free(tmp);
	return (FALSE);
}

int			ft_check_ok(t_stack *s, int which)
{
	int		rot;
	size_t	size;

	size = (which == 1) ? s->size_b : s->size_a;
	if ((which == 1 && s->size_b == 0)
			|| (which == 0 && s->size_a == 0))
		return (-1);
	if ((rot = ft_check_rotate(which ? s->b : s->a, size, which)))
		return (rot);
	return (FALSE);
}

int			ft_reposition(t_stack *s, int *ret_a, int *ret_b, int exec)
{
	int		rot_a;
	int		rot_b;

	rot_a = 0;
	rot_b = 0;
	*ret_a = ft_check_ok(s, 0);
	*ret_b = ft_check_ok(s, 1);
	if (*ret_a > 0 && exec)
		rot_a = *ret_a;
	if (*ret_b > 0 && exec)
		rot_b = *ret_b;
	while (rot_a-- > 0 && rot_b-- > 0)
		ft_cmd(ft_exec_rotate, s, "rr");
	while (rot_a-- > 0)
		ft_cmd(ft_exec_rotate, s, "ra");
	while (rot_b-- > 0)
		ft_cmd(ft_exec_rotate, s, "rb");
	return (*ret_a && *ret_b ? TRUE : FALSE);
}
