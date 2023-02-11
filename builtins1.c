/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:05:26 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/10 22:12:22 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	to_print(char	**av, int i)
{
	int	j;

	j = i;
	while (av[i + 1])
	{
		printf("%s ", av[i]);
		i++;
	}
	if (j == 2)
		printf("%s", av[i]);
	else if (j == 1)
		printf("%s\n", av[i]);
}

void	echo(char **av)
{
	int	i;

	i = 0;
	while (av[1] && av[1][i] && av[1][0] == '-')
	{
		i++;
		if (av[1][i] != 'n')
			break ;
	}
	if (!av[1][i])
		to_print(av, 2);
	else
		to_print(av, 1);
	exit(0);
}

void	pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
}

void	env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		printf("%s\n", envp[i++]);
}

void	cd(char *path)
{
	int	r;

	r = chdir(path);
	if (r)
	{
		if (errno == EACCES)
			printf("%s: Permission denied\n", path);
		// else if (errno = ELOOP)
		// else if (errno = ENAMETOOLONG)
		else if (errno == ENOENT)
			printf("%s: No such file or directory\n", path);
		else if (errno == ENOTDIR)
			printf("%s: Not a directory\n", path);
		exit (1);
	}
	printf("%s", getcwd(0, 0));
}
