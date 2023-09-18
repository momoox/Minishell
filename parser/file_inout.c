/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_inout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:40 by momox             #+#    #+#             */
/*   Updated: 2023/09/17 22:05:38 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	file_inout(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (temp->token == REDIR_IN)
		{
			temp->next->token = REDIR_IN;
			temp = temp->next;
		}
		else if (temp->token == REDIR_OUT)
		{
			temp->next->token = REDIR_OUT;
			temp = temp->next;
		}
		else if (temp->token == REDIR_APPEND)
		{
			temp->next->token = REDIR_APPEND;
			temp = temp->next;
		}
		temp = temp->next;
	}
}
