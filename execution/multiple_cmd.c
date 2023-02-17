/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:05:18 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/18 00:27:12 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// reads from pipe 1 and write to pipe 2
void	odd_child(int i, int out, t_pipe p)
{
	close(p.p1[1]);
	close(p.p2[0]);
	dup2(p.p1[0], 0);
	close(p.p2[0]);
	if (i == -1)
	{
		dup2(out, 1);
		close(out);
	}
	else
		dup2(p.p2[1], 1);
	close(p.p2[1]);
}
// reads from pipe 2 and writes to pipe 1
void	even_child(int i, int in, int out, t_pipe p)
{
	close(p.p2[1]);
	close(p.p1[0]);
	if (!i)
	{
		dup2(in, 0);
		close(in);		
	}
	else
		dup2(p.p2[0], 0);
	close(p.p2[0]);
	if (i == -1)
	{
		dup2(out, 1);
		close(out);
	}
	else
		dup2(p.p1[1], 1);
	close(p.p1[1]);
}

int	is_parent(int *id, int i)
{
	while (i >= 0)
	{
		if (id[i])
			return (0);
		i--;
	}
	return (1);
}

void	child_process(t_cmd cmd, char **env, int i, t_pipe p)
{
	char	**path;
	char	**utils;
	char	*temp;

	cmd_checker(p, cmd, i);
	path = ft_split(find_path(env), ':');
	utils = ft_split(cmd.cmd, 32);
	temp = utils[0];
	utils[0] = ft_strjoin("/", temp);
	if (!path[0])
	{
		ft_dprintf("%s: No such file or directory", utils[0]);
		return ;
	}
	temp = check_path(path, utils);
	free_strs(path);
	execve(temp, utils, env);
}

void	multiple_cmds(int count, t_cmd *cmd, char **env)
{
	int		id[count];
	t_pipe	p;
	t_cmd	*temp;
	int		i;

	temp = cmd;
	i = 0;
	pipe(p.p1);
	pipe(p.p2);
	while (temp && i < count)
	{
		// if (is_parent(id, i))
			id[i] = fork();
		// if (is_parent(id, i))
		if (id[i] == 0)
			child_process(*cmd, env, i, p);
		i++;
		temp = temp->next;
	}
}