/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:10:09 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/21 15:27:33 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

int	main(int ac, char **av, char **env)
{
	t_cmd	*d;
	t_cmd	*c;
	t_cmd	*b;

	(void)ac;
	// (void)av;
	// (void)env;
	c = (t_cmd *)malloc(sizeof(t_cmd));
	b = (t_cmd *)malloc(sizeof(t_cmd));
	d = (t_cmd *)malloc(sizeof(t_cmd));
	d->in = 0;
	// d.out = 1;
	d->cmd = strdup(av[1]);
	d->next = c;
	// c.out = 1;
	c->cmd = strdup(av[2]);
	c->in = -2; 
	c->next = b;
	b->cmd = strdup(av[3]);
	b->in = -2;
	b->out = 1;
	b->next = 0;
	// check(d, env);
	// printf("%d\n", i);
	// dup2(i, 1);
	// printf("test");
	// check(&d, env);
	multiple_cmds(ac - 1, d, env);
	// system("leaks minishell");
}