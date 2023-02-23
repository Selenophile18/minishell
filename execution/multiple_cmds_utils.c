/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:37:34 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/20 19:15:32 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_checker(t_pipe p, t_cmd cmd, int i)
{
	if (i % 2 == 0)
	{
		if (cmd.next)
			even_child(i, cmd.in, cmd.out, p);
		else
			even_child(-1, cmd.in, cmd.out, p);
	}
	else
	{
		if (!cmd.next)
		{
			// printf("here\n");
			odd_child(-1, cmd.in, cmd.out, p);
		}
		else
			odd_child(i, cmd.in, cmd.out, p);
	}
}
