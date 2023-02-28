/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:21:49 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/28 21:29:04 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_path(t_env	env)
{
	char	*path;
	int		i;

	i = 0;
	while (env.key)
	{
		path = ft_strnstr(env.key, "PATH=", 5);
		if (path)
			return (env.value);
		i++;
	}
	return (0);
}

void	ft_dprintf(char *format, char *str)
{
	int	temp;

	temp = dup(1);
	printf("");
	dup2(2, 1);
	printf(format, str);
	dup2(temp, 1);
	close(temp);
}

// char	*find_path(char	**env)
// {
// 	char	*path;
// 	int		i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		path = ft_strnstr(env[i], "PATH=", 5);
// 		if (path)
// 			return (path + 5);
// 		i++;
// 	}
// 	return (0);
// }

void	free_env(t_env *env)
{
	free(env->key);
	free(env->value);
	free(env);
}

void	free_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**ls_to_arr(t_env *env)
{
	t_env	*temp;
	char	**env_var;
	char	*hold;
	int		i;

	i = 0;
	temp = env;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	env_var = (char **)ft_calloc(sizeof(char *), i);
	temp = env;
	i = 0;
	while (temp)
	{
		hold = ft_strjoin(temp->key, "=");
		env_var[i++] = ft_strjoin(hold, temp->value);
		temp = temp->next;
	}
	return (env_var);
}