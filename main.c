/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:10:09 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/16 15:10:18 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

int	main(int ac, char **av, char **env)
{
	// t_cmd	d;

	(void)ac;
	(void)av;
	(void)env;
	// d.in = 0;
	// d.out = 1;
	// d.cmd = av[1];
	// d.next = 0;
	// check(d, env);
	// printf("%d\n", i);
	// dup2(i, 1);
	// printf("test");
	ft_dprintf("%s: gjgksfbkj\n", "hajar");
	printf("%s: gjgksfbkj\n", "hajar2");
}