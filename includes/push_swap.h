/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:34:02 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 13:40:59 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void			ft_make_simple(t_stack *s, char **buf);
int				ft_is_the_biggest(long *tab, size_t size, long cur);
int				ft_is_the_smallest(long *tab, size_t size, long cur);
int				ft_med_stack(long *tab, int size);
void			ft_cmd(int (*f)(t_stack *s, char *str), t_stack *s, char *str);
int				ft_reposition(t_stack *s, int *ret_a, int *ret_b, int exec);
int				ft_process_sort(t_stack *s);
int				ft_process_sort500(t_stack *s);
int				ft_over_pivot(long *tab, size_t size, long pivot, int which);
void			ft_three_a(t_stack *s);
void			ft_three_b(t_stack *s);
int				ft_third(long *tab, int size);
int				ft_post_process(t_stack *s, char **buf, char **tab);
int				ft_is_good(long *tab, size_t size, int which);

#endif
