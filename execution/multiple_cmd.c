/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:05:18 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/21 15:05:32 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
// reads from pipe 1 and write to pipe 2
void	odd_child(int i, int in, int out, t_pipe p)
{
	close(p.p1[1]);
	close(p.p2[0]);
	if (in > -1)
	{
		if (in)
		{
			dup2(in, 0);
			close(in);
		}
	}
	else
		dup2(p.p1[0], 0);
	close(p.p1[0]);
	// printf("%d, %d\n", p.p1[0], p.p2[1]);
	if (i == -1)
	{
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
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
	if (!i || in > -1)
	{
		if (in)
		{
			dup2(in, 0);
			close(in);
		}
	}
	else
		dup2(p.p2[0], 0);
	close(p.p2[0]);
	// printf("%d, %d\n", p.p2[0], p.p1[1]);
	if (i == -1)
	{
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
	}
	else
		dup2(p.p1[1], 1);
	close(p.p1[1]);
}

int	ft_wait(int *id, int i)
{
	int	status;
	int	n;
	int	st;

	n = waitpid(id[i], &status, 0);
	while (n != -1)
		n = waitpid(-1, &st, 0);
	printf("LOL\n");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

void	child_process(t_cmd cmd, char **env, int i, t_pipe p)
{
	char	**path;
	char	**utils;
	char	*temp;
	// int		j;

	// printf("%s %d\n", cmd.cmd, i);
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
	int		i;

	i = 0;
	pipe(p.p1);
	pipe(p.p2);
	while (cmd && i < count)
	{
		id[i] = fork();
		if (id[i] == 0)
			child_process(*cmd, env, i, p);
		i++;
		cmd = cmd->next;
	}
	close(p.p1[0]);
	close(p.p1[1]);
	close(p.p2[0]);
	close(p.p2[1]);
	ft_wait(id, i);
}