/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:06:13 by momox             #+#    #+#             */
/*   Updated: 2023/09/06 16:01:05 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_list(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%d: list->content = %s\n", i++, list->content);
		printf("list->token = %d\n", list->token);
		// if (list->next->next == NULL)
		// 	return ;
		list = list->next;
	}
}

void	print_list_token(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		printf("%d: list->token = %d\n", i++, list->token);
		list = list->next;
	}
}
