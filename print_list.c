/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:06:13 by momox             #+#    #+#             */
/*   Updated: 2023/10/02 19:31:06 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *list)
{
	if (list == NULL)
	{
		printf("	NULL\n");
		return ;
	}
	printf("=====PRINT LIST=====\n");
	while (list)
	{

		printf("List\n");
		printf("	list->content = %s\n", list->content);
		printf("	list->Token = %d\n", list->token);
		if(list->cmd) 
		for (int i = 0; list->cmd[i]; i++)
			printf("		list->cmd[%d] = %s\n",i, list->cmd[i]);
		// if (list->token == COMMAND && list->cmd)
		// {
		// 	printf("tab 0 = %s\n", list->cmd[0]);
		// 	printf("tab 1 = %s\n", list->cmd[1]);
		// }
		list = list->next;
	}
	printf("	====================\n\n");
}
		// if (list->next->next == NULL)
		// printf("list->token = %d\n", list->token);
		// 	return ;