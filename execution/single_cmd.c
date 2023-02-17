/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:14:54 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/17 23:38:51 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fd(t_cmd cmd)
{
	if (cmd.in)
	{
		dup2(cmd.in, 0);
		close(cmd.in);
	}
	if (cmd.out != 1)
	{
		dup2(cmd.out, 1);
		close(cmd.out);
	}
}

char	*check_path(char	**path, char	**utils)
{
	int	i;
	char	*temp;

	i = 0;
	while (path[i])
	{
		if (!access(utils[0], F_OK && X_OK))
		{
			temp = utils[0];
			break ;
		}
		temp = ft_strjoin(path[i], utils[0]);
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

void	single_cmd(t_cmd *cmd, char **utils, char **env)
{
	char	**path;
	char	*temp;
	int		i;

	path = ft_split(find_path(env), ':');
	i = 0;
	if (!path[0])
	{
		ft_dprintf("%s: No such file or directory", utils[0]);
		return ;
	}
	temp = check_path(path, utils);
	free_strs(path);
	fd(*cmd);
	execve(temp, utils, env);
}