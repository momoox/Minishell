/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:44:31 by momox             #+#    #+#             */
/*   Updated: 2023/09/13 17:16:29 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tab_env(t_data *data, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		data->env[j] = malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		ft_strlcpy(data->env[j], env[i], ft_strlen(env[i]) + 1);
		j++;
		i++;
	}
	data->env[j] = NULL;
}
