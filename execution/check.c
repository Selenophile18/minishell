/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:21:01 by hhattaki          #+#    #+#             */
/*   Updated: 2023/03/01 00:37:06 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strcmp("echo", cmd))
		return (1);
	if (!ft_strcmp("cd", cmd))
		return (1);
	if (!ft_strcmp("exit", cmd))
		return (1);
	if (!ft_strcmp("unset", cmd))
		return (1);
	if (!ft_strcmp("env", cmd))
		return (1);
	if (!ft_strcmp("pwd", cmd))
		return (1);
	if (!ft_strcmp("export", cmd))
		return (1);
	return (0);
}

void	call_builtin(t_env **env_var, t_cmd	*cmd)
{
	if (!ft_strcmp("echo", cmd->cmd[0]))
		echo(cmd->cmd);
	else if (!ft_strcmp("cd", cmd->cmd[0]))
		cd(*cmd, env_var);
	else if (!ft_strcmp("unset", cmd->cmd[0]))
		unset(cmd->cmd, *env_var);
	else if (!ft_strcmp("pwd", cmd->cmd[0]))
		pwd();
	else if (!ft_strcmp("env", cmd->cmd[0]))
		env(*env_var);
}

void	check(t_cmd *cmd, t_env **env)
{
	int		i;
	pid_t	id;

	cmd->cmd[0] = ft_strjoin("/", cmd->cmd[0]);
	i = 0;
	if (!cmd->next)
	{
		if (is_builtin)
			call_builtin(env, cmd);
		else
		{
			id = fork();
			if (!id)
				single_cmd(cmd, env);
		}
	}
	else
		multiple_cmds(i, cmd, env);
}
