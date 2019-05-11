/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:00:47 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 15:00:43 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_forgot(t_stack *s, char **buf, char **tab, int i)
{
	if ((ft_strequ(tab[i], "rr") && ft_strequ(tab[i + 1], "rrr"))
			|| (ft_strequ(tab[i], "rrr") && ft_strequ(tab[i + 1], "rr")))
		return (1);
	else if ((ft_strequ(tab[i], "ra") && ft_strequ(tab[i + 1], "rra"))
			|| (ft_strequ(tab[i], "rra") && ft_strequ(tab[i + 1], "ra"))
			|| (ft_strequ(tab[i], "rb") && ft_strequ(tab[i + 1], "rrb"))
			|| (ft_strequ(tab[i], "rrb") && ft_strequ(tab[i + 1], "rb")))
		return (1);
	else if ((ft_strequ(tab[i], "ss") && ft_strequ(tab[i + 1], "ss"))
			|| (ft_strequ(tab[i], "sa") && ft_strequ(tab[i + 1], "sa"))
			|| (ft_strequ(tab[i], "sb") && ft_strequ(tab[i + 1], "sb")))
		return (1);
	if (ft_strequ(tab[i], "pa"))
	{
		s->size_b--;
		s->size_a++;
	}
	else if (ft_strequ(tab[i], "pb"))
	{
		s->size_a--;
		s->size_b++;
	}
	ft_joinfree(buf, tab[i], 1);
	ft_joinfree(buf, "\n", 1);
	return (0);
}

static int	ft_loop_tab(t_stack *s, char **buf, char **tab)
{
	int		i;
	int		ret;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		ret = 0;
		if ((ret = ft_post_process(s, buf, tab + i)))
			;
		else if ((ft_strequ(tab[i], "sa") && ft_strequ(tab[i + 1], "sb"))
				|| (ft_strequ(tab[i], "sb") && ft_strequ(tab[i + 1], "sa")))
			ft_joinfree(buf, "ss\n", 1);
		else if ((ft_strequ(tab[i], "ra") && ft_strequ(tab[i + 1], "rb"))
				|| (ft_strequ(tab[i], "rb") && ft_strequ(tab[i + 1], "ra")))
			ft_joinfree(buf, "rr\n", 1);
		else if ((ft_strequ(tab[i], "rra") && ft_strequ(tab[i + 1], "rrb"))
				|| (ft_strequ(tab[i], "rrb") && ft_strequ(tab[i + 1], "rra")))
			ft_joinfree(buf, "rrr\n", 1);
		else
			i += (ft_forgot(s, buf, tab, i) - 1);
		i = ret ? i + ret : i + 2;
	}
	return (i);
}

void		ft_make_simple(t_stack *s, char **buf)
{
	char	**tab;
	int		i;

	if (!(tab = ft_strsplit(*buf, '\n')))
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	ft_strdel(buf);
	i = ft_loop_tab(s, buf, tab);
	if (tab[i])
	{
		ft_joinfree(buf, tab[i], 1);
		ft_joinfree(buf, "\n", 1);
	}
	ft_free_tab_str(tab);
}
