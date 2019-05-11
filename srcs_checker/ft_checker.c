/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:54:02 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 14:58:14 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_is_ok(long *tab, int size)
{
	int		i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] < tab[i + 1])
		{
			ft_putendl("KO");
			return ;
		}
		i++;
	}
	ft_putendl("OK");
}

static char	*ft_get_av_checker(char **av)
{
	char	**tab;
	char	*s;
	int		i;
	int		count;

	s = NULL;
	count = 0;
	while (av[count])
	{
		tab = ft_strsplit(av[count], ' ');
		i = 0;
		while (tab[i])
		{
			s = ft_strjoinfree(s, tab[i++], FIRST);
			s = ft_strjoinfree(s, "\n", FIRST);
		}
		ft_free_tab_str(tab);
		count++;
	}
	return (s);
}

static int	ft_get_option_extend(char *s, int *flag_v, int *flag_c)
{
	int		i;

	i = 0;
	while (s[i] == '-')
	{
		if (s[i + 1] == 'c' || s[i + 1] == 'v')
			i++;
		else
			break ;
		while (s[i] == 'c' || s[i] == 'v')
		{
			if (s[i] == 'v')
				*flag_v = 1;
			else
				*flag_c = 1;
			i++;
		}
		i++;
	}
	return (i);
}

static char	**ft_get_option(char *s, int *flag_v, int *flag_c)
{
	int		i;
	char	**tab;

	i = ft_get_option_extend(s, flag_v, flag_c);
	if (!(tab = ft_strsplit(s + i, '\n')) || !tab[0])
	{
		ft_strdel(&s);
		ft_free_tab_str(tab);
		exit(0);
	}
	ft_strdel(&s);
	i = -1;
	while (tab[++i])
	{
		if (ft_strequ(tab[i], "-")
			|| !(ft_str_is_numeric(tab[i]) || (tab[i][0] == '-'
			&& ft_str_is_numeric(tab[i] + 1))))
		{
			ft_free_tab_str(tab);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
	}
	return (tab);
}

int			main(int ac, char **av)
{
	t_stack	s;
	int		flag_v;
	int		flag_c;
	char	*s_arg;
	char	**arg;

	if (ac == 1)
		return (0);
	s.a = NULL;
	s.b = NULL;
	flag_v = 0;
	flag_c = 0;
	s_arg = ft_get_av_checker(av + 1);
	arg = ft_get_option(s_arg, &flag_v, &flag_c);
	s.size = ft_size_of_arg(arg);
	ft_set_a_and_b(&s, arg, s.size);
	ft_free_tab_str(arg);
	ft_exec(&s, flag_v, flag_c);
	ft_is_ok(s.a, s.size_a);
	ft_free_stack(&s);
	return (0);
}
