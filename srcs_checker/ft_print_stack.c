/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:54:19 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 14:18:44 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static size_t	ft_size_of_int(int nb)
{
	size_t	size;

	size = 0;
	if (nb <= 0)
		size++;
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void		ft_print_nb_of_char(size_t nb, char c)
{
	while (nb > 0)
	{
		ft_putchar(c);
		nb--;
	}
}

static void		ft_print_case(long *tab, size_t size_tab, size_t i)
{
	size_t nb_size;

	ft_putstr("\033[33m");
	if (i < size_tab)
	{
		nb_size = 21 - ft_size_of_int(tab[i]);
		ft_print_nb_of_char(nb_size / 2, ' ');
		nb_size -= nb_size / 2;
		ft_putnbr(tab[i]);
		ft_print_nb_of_char(nb_size - 1, ' ');
	}
	else
		ft_putstr("         .          ");
	ft_putstr("\033[0m");
}

void			ft_print_stack(t_stack *s)
{
	size_t	i;
	size_t	size_max;

	size_max = s->size;
	i = 0;
	ft_putstr("\n    |       \033[32mstack A\033[0m       |       ");
	ft_putendl("\033[32mstack B\033[0m       |");
	ft_putendl("    |                     |                     |");
	while (i < size_max)
	{
		ft_putstr("    |");
		ft_print_case(s->a, s->size_a, size_max - 1 - i);
		ft_putstr(" | ");
		ft_print_case(s->b, s->size_b, size_max - 1 - i);
		ft_putendl("|");
		i++;
	}
}
