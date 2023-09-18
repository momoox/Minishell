/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:44:18 by momox             #+#    #+#             */
/*   Updated: 2023/09/17 22:09:03 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_tab(t_data *data)
{
	t_list	*temp;

	temp = data->list;
	data->list->cmd = malloc(sizeof(char *) * 1);
	data->list->cmd[0] = NULL;
	while (temp && temp->token != PIPE)
	{
		if (temp->token == COMMAND)
			data->list->cmd = ft_tabadd_back(data->list->cmd, temp->content);
		temp = temp->next;
	}
}
