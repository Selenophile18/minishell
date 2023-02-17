/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:10:09 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/17 23:58:15 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

int	main(int ac, char **av, char **env)
{
	t_cmd	d;
	t_cmd	c;

	(void)ac;
	// (void)av;
	// (void)env;
	d.in = 0;
	// d.out = 1;
	d.cmd = av[1];
	d.next = &c;
	c.out = 1;
	c.cmd = av[2];
	c.next = 0;
	// check(d, env);
	// printf("%d\n", i);
	// dup2(i, 1);
	// printf("test");
	// check(&d, env);
	multiple_cmds(2, &d, env);
	// system("leaks minishell");
}