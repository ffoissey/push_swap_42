/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:54:11 by ffoissey          #+#    #+#             */
/*   Updated: 2019/04/02 14:27:48 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_process(t_stack *s, char **str)
{
	int		ret;

	ret = 0;
	if (**str == 's')
		ret = ft_exec_swap(s, *str);
	else if (**str == 'p')
		ret = ft_exec_push(s, *str);
	else if (**str == 'r')
		ret = ft_exec_rotate(s, *str);
	if (ret == 0)
	{
		ft_strdel(str);
		ft_exit(s);
	}
}

static void	ft_exec_flag_c(char *cmd, int flag_v)
{
	if (flag_v)
	{
		ft_printf("\n\n    --------------- Last CMD: \033[36m%-4s\033[0m", cmd);
		ft_printf("---------------\n\n\n");
	}
	else
		ft_printf("Last CMD: \033[36m%-4s\033[0m\n", cmd);
}

void		ft_exec(t_stack *s, int flag_v, int flag_c)
{
	char	*line;
	int		step;

	step = 1;
	line = NULL;
	if (flag_v)
	{
		ft_printf("\033[2J\033[;H");
		ft_printf("---> \033[031mINIT\033[0m\n");
		ft_print_stack(s);
	}
	while (get_next_line(0, &line) > 0)
	{
		ft_process(s, &line);
		if (flag_v)
		{
			ft_printf("\033[2J\033[;H");
			ft_printf("---> \033[031mSTEP %d\033[0m\n", step++);
			ft_print_stack(s);
		}
		if (flag_c)
			ft_exec_flag_c(line, flag_v);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
