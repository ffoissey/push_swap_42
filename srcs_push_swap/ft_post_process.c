/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:02:43 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 15:01:16 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_how_push(char **tab, int which, int *tmp)
{
	int		i;

	i = 0;
	while ((ft_strequ(tab[i], which ? "pb" : "pa")))
	{
		i++;
		(*tmp)++;
	}
	while ((ft_strequ(tab[i], which ? "pa" : "pb")))
	{
		i++;
		(*tmp)--;
	}
	return (i);
}

static int	ft_reduce_push(t_stack *s, char **buf, char **tab, int which)
{
	int		i;
	int		tmp;

	tmp = 0;
	i = ft_how_push(tab, which, &tmp);
	while (tmp > 0)
	{
		*buf = ft_strjoinfree(*buf, which ? "pb\n" : "pa\n", FIRST);
		tmp--;
		s->size_a = which ? s->size_a - 1 : s->size_a + 1;
		s->size_b = which ? s->size_b + 1 : s->size_b - 1;
	}
	while (tmp < 0)
	{
		*buf = ft_strjoinfree(*buf, which ? "pa\n" : "pb\n", FIRST);
		tmp++;
		s->size_a = which ? s->size_a + 1 : s->size_a - 1;
		s->size_b = which ? s->size_b - 1 : s->size_b + 1;
	}
	return (i);
}

static int	ft_reduce_rotate(t_stack *s, char **buf, char **tab, int which)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	str = tab[i];
	while (ft_strequ(tab[i], tab[i + 1]))
		i++;
	tmp = ++i;
	if ((which && tmp > (int)s->size_b / 2)
			|| (!which && tmp > (int)s->size_a / 2))
		tmp = which ? tmp - s->size_b : tmp - s->size_a;
	if (tmp >= 0)
		i = 0;
	while (tmp < 0)
	{
		if (which)
			*buf = ft_strjoinfree(*buf, ft_strequ(str, "rb")
					? "rrb\n" : "rb\n", FIRST);
		else
			*buf = ft_strjoinfree(*buf, ft_strequ(str, "ra")
					? "rra\n" : "ra\n", FIRST);
		tmp++;
	}
	return (i);
}

int			ft_post_process(t_stack *s, char **buf, char **tab)
{
	int		i;

	i = 0;
	if (ft_strequ(tab[i], "pa") && ft_strequ(tab[i + 1], "pa"))
		i = ft_reduce_push(s, buf, tab, 0);
	else if (ft_strequ(tab[i], "pb") && ft_strequ(tab[i + 1], "pb"))
		i = ft_reduce_push(s, buf, tab, 0);
	else if ((ft_strequ(tab[i], "ra") || ft_strequ(tab[i], "rra"))
			&& ft_strequ(tab[i], tab[i + 1]))
		i = ft_reduce_rotate(s, buf, tab, 0);
	else if ((ft_strequ(tab[i], "rb") || ft_strequ(tab[i], "rrb"))
			&& ft_strequ(tab[i], tab[i + 1]))
		i = ft_reduce_rotate(s, buf, tab, 1);
	return (i);
}
