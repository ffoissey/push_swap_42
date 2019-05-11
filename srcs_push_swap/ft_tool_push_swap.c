/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:02:52 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:29:15 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_the_biggest(long *tab, size_t size, long big)
{
	size_t	i;

	if (!size || size == 1)
		return (TRUE);
	i = 0;
	while (i < size)
	{
		if (tab[i] > big)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_is_the_smallest(long *tab, size_t size, long small)
{
	size_t	i;

	if (!size || size == 1)
		return (TRUE);
	i = 0;
	while (i < size)
	{
		if (tab[i] < small)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_third(long *tab, int size)
{
	long	*cpy;
	int		i;
	int		ret;

	i = 0;
	if (!(cpy = (long *)ft_malloc(sizeof(long) * size)))
		return (tab[size - 1]);
	while (i < size)
	{
		cpy[i] = tab[i];
		i++;
	}
	ft_insertsort_long(cpy, size);
	ret = cpy[size - 1];
	ft_free(cpy);
	return (ret);
}

int		ft_med_stack(long *tab, int size)
{
	long	*cpy;
	int		i;
	int		ret;
	int		tmp_size;

	i = -1;
	if (!(cpy = (long *)ft_malloc(sizeof(long) * size)))
		return (tab[size - 1]);
	while (++i < size)
	{
		cpy[i] = tab[i];
	}
	ft_insertsort_long(cpy, size);
	tmp_size = size;
	if (size >= 300)
		size = size / 4 + size % 4;
	else if (size >= 12)
		size = size / 3 + size % 3;
	else
		size = size / 2;
	if (tmp_size < size)
		size = tmp_size - 1;
	ret = size > 0 ? cpy[size] : cpy[0];
	ft_free(cpy);
	return (ret);
}

void	ft_cmd(int (*f)(t_stack *s, char *str), t_stack *s, char *str)
{
	f(s, str);
	ft_joinfree(&s->buf, str, 1);
	ft_joinfree(&s->buf, "\n", 1);
}
