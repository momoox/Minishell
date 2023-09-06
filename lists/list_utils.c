/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:32:42 by momox             #+#    #+#             */
/*   Updated: 2023/09/06 16:01:00 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = str;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void	lstadd_front(t_list **first, t_list *new)
{
	if (*first == NULL)
		*first = new;
	else
	{
		new->next = *first;
		*first = new;
	}
}

void	lstadd_back(t_list **first, t_list *new)
{
	t_list	*tmp;

	if (*first == NULL)
		*first = new;
	else
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	list_back(t_list *list)
{
	while (list->prev)
		list = list->prev;
}
