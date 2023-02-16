/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:05:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/16 17:44:54 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;	
}	t_env;

// typedef struct t_utils
// {
// 	int		is_builtin;
// }

typedef struct s_cmd
{
	char			*cmd;
	int				in;
	int				out;
	struct s_cmd	*next;
}	t_cmd;

/*---------builtins---------*/
int		pwd(void);
int		env(t_env *envp);
/// handle cd no arg and with ~ take to home, cd - previous path 
int		cd(char *path);
int		echo(char **av);
void	unset(char **key, t_env	*env_vars);

/*----------utils----------*/
void	free_env(t_env *env);
void	free_strs(char **str);
// char	*find_path(t_env	env);
char	*find_path(char	**env);
void	ft_dprintf(char *format, char *str);
char	**ls_to_arr(t_env *env);

/*---------checking--------*/
void	check(t_cmd cmd, char **env);

/*------single_command-----*/
void	single_cmd(t_cmd cmd, char **utils, char **env);

/*-----multiple_command----*/

#endif