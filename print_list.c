/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:06:13 by momox             #+#    #+#             */
/*   Updated: 2023/10/05 19:33:40 by momox            ###   ########.fr       */
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
	// printf("\033[0;34m=====PRINT LIST=====\033[0m\n");
	// while (list)
	// {

		// printf("\033[0;34mList\033[0m\n");
		printf("	list->content = \033[0;32m[%s]\033[0m\n", list->content);
		printf("	list->Token = \033[0;31m[%d]\033[0m\n", list->token);
		if(list->cmd) 
		for (int i = 0; list->cmd[i]; i++)
			printf("		list->cmd\033[0;31m[%d]\033[0m = \033[0;32m[%s]\033[0m\n",i, list->cmd[i]);
		// if (list->token == COMMAND && list->cmd)
		// {
		// 	printf("tab 0 = %s\n", list->cmd[0]);
		// 	printf("tab 1 = %s\n", list->cmd[1]);
		// }
		// list = list->next;
	// }
	// printf("\033[0;35m	====================\033[0m\n\n");
}
		// if (list->next->next == NULL)
		// printf("list->token = %d\n", list->token);
		// 	return ;
