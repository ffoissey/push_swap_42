/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:56:21 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 14:18:45 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

void			ft_set_a_and_b(t_stack *s, char **av, int ac);
void			ft_print_stack(t_stack *s);
int				ft_check_ok(t_stack *s, int which);
void			ft_exec(t_stack *s, int flag_v, int flag_c);

#endif
