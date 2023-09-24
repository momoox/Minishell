/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:44:18 by momox             #+#    #+#             */
/*   Updated: 2023/09/24 19:56:29 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_tab(t_data *data)
{
	t_list	*temp;
	t_list	*tab;

	temp = data->list;
	tab = data->list;
	while (temp)
	{
		tab->cmd = malloc(sizeof(char *) * 1);
		tab->cmd[0] = NULL;
		while (temp && temp->token != PIPE)
		{
			if (temp->token == COMMAND)
				tab->cmd = ft_tabadd_back(tab->cmd, temp->content);
			temp = temp->next;
			//delete prev cmd avant prochain pipe
		}
		if (temp)
		{
			temp = temp->next;
			tab = temp;
		}
	}
}
