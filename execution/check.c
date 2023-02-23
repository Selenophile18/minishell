/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:21:01 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/20 09:55:22 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strncmp("echo", cmd, 0))
		return (1);
	if (!ft_strncmp("cd", cmd, 0))
		return (1);
	if (!ft_strncmp("exit", cmd, 0))
		return (1);
	if (!ft_strncmp("unset", cmd, 0))
		return (1);
	if (!ft_strncmp("env", cmd, 0))
		return (1);
	if (!ft_strncmp("pwd", cmd, 0))
		return (1);
	if (!ft_strncmp("export", cmd, 0))
		return (1);
	return (0);
}

void	call_builtin(t_env *env_var, char **b_in)
{
	if (!ft_strncmp("echo", b_in[0], 0))
		echo(++b_in);
	else if (!ft_strncmp("cd", b_in[0], 0))
		cd(b_in[1]);
	else if (!ft_strncmp("unset", b_in[0], 0))
		unset(++b_in, env_var);
	else if (!ft_strncmp("pwd", b_in[0], 0))
		pwd();
	else if (!ft_strncmp("env", b_in[0], 0))
		env(env_var);
}

void	check(t_cmd *cmd, char **env)
{
	char	**cmd_split;
	char	*temp;
	int		i;

	cmd_split = ft_split(cmd->cmd, 32);
	temp = cmd_split[0];
	cmd_split[0] = ft_strjoin("/", temp);
	i = 0;
	if (!cmd->next)
		single_cmd(cmd, cmd_split, env);
	else
	{
		while (cmd)
		{
			if (is_builtin(cmd_split[0]))
				// call_builtin(env, cmd_split);
				printf("1");
			else
			{
				// printf("[%p]", cmd->cmd);
				multiple_cmds(i, cmd, env);
			}
			i++;
			cmd = cmd->next;
		}
	}
}
