/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:02:47 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 14:37:16 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_solution(char *buf)
{
	char	**tab;
	int		i;

	if (!(tab = ft_strsplit(buf, '\n')))
	{
		ft_putendl_fd("Error", 2);
		return ;
	}
	ft_strdel(&buf);
	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
	ft_free_tab_str(tab);
}

static void	ft_join_tab(char **tab, char **s)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!(ft_str_is_numeric(tab[i]) || (tab[i][0] == '-'
			&& ft_str_is_numeric(tab[i] + 1))))
		{
			ft_free_tab_str(tab);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		ft_joinfree(s, tab[i], 1);
		ft_joinfree(s, "\n", 1);
		i++;
	}
}

static char	**ft_get_av(char **av)
{
	char	**arg;
	char	**tab;
	char	*s;
	int		count;

	s = NULL;
	count = 0;
	while (av[count])
	{
		tab = ft_strsplit(av[count], ' ');
		ft_join_tab(tab, &s);
		ft_free_tab_str(tab);
		count++;
	}
	arg = ft_strsplit(s, '\n');
	ft_strdel(&s);
	return (arg);
}

int			main(int ac, char **av)
{
	t_stack	s;
	char	**arg;

	if (ac == 1)
		return (0);
	s.a = NULL;
	s.b = NULL;
	s.buf = NULL;
	arg = ft_get_av(av + 1);
	s.size = ft_size_of_arg(arg);
	ft_set_a_and_b(&s, arg, s.size);
	s.size < 200 ? ft_process_sort(&s) : ft_process_sort500(&s);
	if (s.buf)
	{
		s.size_a = s.size;
		s.size_b = 0;
		ft_make_simple(&s, &s.buf);
		ft_print_solution(s.buf);
	}
	ft_flush_memory();
//	ft_free_stack(&s);
//	ft_free_tab_str(arg);
	return (0);
}
