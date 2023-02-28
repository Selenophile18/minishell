/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmds_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:37:34 by hhattaki          #+#    #+#             */
/*   Updated: 2023/03/01 00:05:25 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_checker(t_pipe p, t_cmd cmd, int *io, int i)
{
	if (i % 2 == 0)
	{
		if (cmd.next)
			even_child(i, io[0], io[1], p);
		else
			even_child(-1, io[0], io[1], p);
	}
	else
	{
		if (!cmd.next)
		{
			// printf("here\n");
			odd_child(-1, io[0], io[1], p);
		}
		else
			odd_child(i, io[0], io[1], p);
	}
}

int	set_in(t_cmd cmd)
{
	int	in;

	if (cmd.in && !cmd.here_doc)
		in = open(cmd.in, O_RDONLY);
	else if (cmd.pipe)
		in = -2;
}
