/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:33:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:40:56 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef	struct	s_stack
{
	long		*a;
	long		*b;
	char		*buf;
	size_t		size;
	size_t		size_a;
	size_t		size_b;
}				t_stack;

int				ft_size_of_arg(char **arg);
int				ft_exec_swap(t_stack *s, char *str);
int				ft_exec_push(t_stack *s, char *str);
int				ft_exec_rotate(t_stack *s, char *str);
void			ft_free_stack(t_stack *s);
void			ft_exit(t_stack *s);
void			ft_set_a_and_b(t_stack *s, char **av, int ac);
int				ft_check_arg(t_stack *s, char *str, size_t i);

#endif
