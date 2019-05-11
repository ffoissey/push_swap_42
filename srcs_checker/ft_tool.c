/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:54:26 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 10:54:28 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_stack(t_stack *s)
{
	if (s->a)
	{
		ft_free(s->a);
		s->a = NULL;
	}
	if (s->b)
	{
		ft_free(s->b);
		s->b = NULL;
	}
}

void	ft_exit(t_stack *s)
{
	ft_free_stack(s);
	write(2, "Error\n", 6);
	exit(1);
}
