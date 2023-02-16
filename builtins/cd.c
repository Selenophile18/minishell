/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:19:09 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/14 15:46:18 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd(char *path)
{
	int	r;

	r = chdir(path);
	if (r)
	{
		if (errno == EACCES || errno == ENOENT || errno == ENOTDIR)
			perror(path);
		return (1);
	}
	printf("%s", getcwd(0, 0));
	return (0);
}
