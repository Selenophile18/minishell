/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:10:09 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/27 22:40:16 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <fcntl.h>

int	main(int ac, char **av, char **env)
{
	t_cmd	*d;
	t_cmd	*c;
	t_cmd	*b;
	t_cmd	*h;
	// t_cmd   *h5;
	char *cmd2[]= {"cat",0};
	char *cmd1[]= {"cat",0};
	char *cmd3[] = {"cat", 0};
	char *cmd4[] = {"ls", 0};
	// char *cmd5[] = {"ls", 0};

	(void)ac;
	(void)av;
	// // (void)av;
	// // (void)env;
	c = (t_cmd *)malloc(sizeof(t_cmd));
	b = (t_cmd *)malloc(sizeof(t_cmd));
	d = (t_cmd *)malloc(sizeof(t_cmd));
	h = (t_cmd *)malloc(sizeof(t_cmd));
	// h5 = (t_cmd *)malloc(sizeof(t_cmd));
	d->in = 0;
	d->out = -2;
	d->arg = cmd1;
	d->next = c;
	c->out = -2;
	c->arg = cmd2;
	c->in = -2;
	c->next = b;
	b->arg = cmd3;
	b->in = -2;
	b->out = -2;
	b->next = h;
	h->arg = cmd4;
	h->in = open("out1", O_RDONLY);;
	h->out = 1;
	h->next = 0;
	// h5->arg = cmd5;
	// h5->in = -2;
	// h5->out = 1;
	// h5->next = 0;
	
	
	// // check(d, env);
	// // printf("%d\n", i);
	// // dup2(i, 1);
	// // printf("test");
	// // check(&d, env);
	// multiple_cmds(ac - 1, d, env);
	// system("leaks minishell");
	multiple_cmds(5, d, env);
	// export(env, av);
	dprintf(2,"\nminishell>");
	while(1);
}