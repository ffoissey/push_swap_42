/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:54:33 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 10:54:34 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long	ft_atol(const char *str)
{
	long	nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((str[0] == '-' && i == 19 && str[i] >= '8')
			|| (str[0] == '-' && i > 19 && ft_isdigit(*(str + i))))
			return (0);
		if (((i == 19 && str[0] == '+') || (i == 18 && str[0] != '-'))
			&& str[i] >= '7')
			return (-1);
		if (((i > 19 && str[0] == '+') || (i > 18 && str[0] != '-'))
			&& ft_isdigit(*(str + i)))
			return (-1);
		nbr = str[i++] - '0' + nbr * 10;
	}
	return (str[0] == '-' ? -nbr : nbr);
}

int		ft_check_arg(t_stack *s, char *str, size_t i)
{
	long	nb;
	size_t	j;

	nb = ft_atol(str);
	j = s->size_a - 1;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	while (j > i)
		if (s->a[j--] == nb)
			return (0);
	if (*str == '-' && *(str + 1))
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	s->a[i] = nb;
	return (1);
}

void	ft_set_a_and_b(t_stack *s, char **av, int ac)
{
	size_t	i;
	int		tmp;

	i = 0;
	s->size_a = s->size;
	s->size_b = 0;
	if (!(s->a = (long *)ft_malloc(sizeof(long) * s->size)))
		ft_exit(s);
	if (!(s->b = (long *)ft_malloc(sizeof(long) * s->size)))
		ft_exit(s);
	tmp = ac;
	while (tmp)
	{
		if (!(ft_check_arg(s, av[i++], (tmp-- - 1))))
			ft_exit(s);
	}
}

int		ft_size_of_arg(char **arg)
{
	int		i;

	i = 0;
	while (arg && arg[i])
		i++;
	return (i);
}
