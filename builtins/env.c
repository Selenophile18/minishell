/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhattaki <hhattaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:17:03 by hhattaki          #+#    #+#             */
/*   Updated: 2023/02/14 18:19:14 by hhattaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env(t_env	*envp)
{
	t_env	*temp;

	temp = envp;
	while (temp)
	{
		printf("%s=%s\n", temp->key, envp->value);
		temp = temp->next;
	}
	return (0);
}