/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:14:54 by hhattaki          #+#    #+#             */
/*   Updated: 2023/03/01 00:26:27 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd(int *io)
{
	if (io[0])
	{
		dup2(io[0], 0);
		close(io[0]);
	}
	if (io[1] != 1)
	{
		dup2(io[1], 1);
		close(io[1]);
	}
}

char	*check_path(char	**path, char	**utils)
{
	int	i;
	char	*temp;
	char	*c;

	i = 0;
	c = ft_strjoin("/", utils[0]);
	while (path[i])
	{
		if (!access(c, F_OK && X_OK))
		{
			temp = utils[0];
			break ;
		}
		temp = ft_strjoin(path[i], c);
		if (!access(temp, F_OK && X_OK))
			break ;
		free (temp);
		i++;
	}
	if (!path[i])
	{
		ft_dprintf("%s: Command not found\n", utils[0]);
		exit (127);
	}
	return (temp);
}

void	single_cmd(t_cmd *cmd, t_env **env)
{
	char	**path;
	char	*temp;
	int		io[2];

	io[0] = set_in(*cmd);
	if (io[0] == -1)
	{
		ft_dprintf("%s: No such file or directory", cmd->in);
		exit (1);
	}
	path = ft_split(find_path(**env), ':');
	if (!path[0])
	{
		ft_dprintf("%s: No such file or directory", cmd->cmd[0]);
		exit(127);
	}
	temp = check_path(path, cmd->cmd);
	free_strs(path);
	fd(io);
	execve(temp, cmd->cmd, ls_to_arr(*env));
}