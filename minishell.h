/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:05:31 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/17 21:28:42 by hhattaki         ###   ########.fr       */
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

typedef struct s_pipe
{
	int	p1[2];
	int	p2[2];
}	t_pipe;


/*---------builtins---------*/
int		pwd(void);
int		env(t_env *envp);
/// handle cd no arg and with ~ take to home, cd - previous path 
int		cd(char *path);
int		echo(char **av);
void	unset(char **key, t_env	*env_vars);
// void	ft_exit(unsigned char n);

/*----------utils----------*/
void	free_env(t_env *env);
void	free_strs(char **str);
// char	*find_path(t_env	env);
char	*find_path(char	**env); //temp
void	ft_dprintf(char *format, char *str);
char	**ls_to_arr(t_env *env);
char	*check_path(char	**path, char	**utils);

/*---------checking--------*/
void	check(t_cmd *cmd, char **env);

/*------single_command-----*/
void	single_cmd(t_cmd *cmd, char **utils, char **env); //temp

/*-----multiple_command----*/
void	even_child(int i, int in, int out, t_pipe p);
void	odd_child(int i, int out, t_pipe p);
void	cmd_checker(t_pipe p, t_cmd cmd, int i);
void	multiple_cmds(int count, t_cmd *cmd, char **env);


#endif