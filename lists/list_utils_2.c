/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:48:56 by momox             #+#    #+#             */
/*   Updated: 2023/09/06 16:00:57 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_here(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		new->prev = 0;
		(*lst) = new;
	}
	else
	{
		new->prev = (*lst);
		if ((*lst)->next)
		{
			new->next = (*lst)->next;
			(*lst)->next->prev = new;
		}
		else
			new->next = NULL;
		(*lst)->next = new;
	}
}

void	ft_lstdel_here(t_list **first, t_list *node_to_delete)
{
	if (!first || !*first || !node_to_delete)
		return ;
	if (node_to_delete->next)
	{
		if (node_to_delete->prev)
			node_to_delete->prev->next = node_to_delete->next;
		else
			*first = node_to_delete->next;
	}
	if (node_to_delete->next)
		node_to_delete->next->prev = node_to_delete->prev;
	else if (!node_to_delete->prev)
		*first = 0;
	free(node_to_delete);
}
