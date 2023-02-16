/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:05:18 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/16 22:29:22 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//reads from pipe 1 and write to pipe 2
void	odd_child(int p1[2], int p2[2])
{
	close(p1[1]);
	close(p2[0]);
	dup2(p1[0], 0);
	close(p2[0]);
	dup2(p2[1], 1);
	close(p2[1]);
}
// reads from pipe 2 and writes to pipe 1
void	even_child(int p1[2], int p2[2])
{
	close(p2[1]);
	close(p1[0]);
	dup2(p2[0], 0);
	close(p2[0]);
	dup2(p1[1], 1);
	close(p1[1])
}

void	multiple_cmds(int count, t_cmd cmd, t_env env)
{
	int	id[count];
	int	p1[2];
	int	p2[2];

	
}