/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regroup_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:53:00 by momox             #+#    #+#             */
/*   Updated: 2023/09/17 19:55:04 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	del_node(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		if (temp->flag_delete == 1 && temp->next)
		{
			temp = temp->next;
			ft_lstdel_here(&list, temp->prev);
		}
		else if (temp->flag_delete == 1)
		{
			ft_lstdel_here(&list, temp);
			return ;
		}
		if (temp->next == NULL)
			return ;
		temp = temp->next;
	}
}

void	regroup_command_2(t_list *list, t_list *save_cmd)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		temp = temp->next;
		while (temp && temp->token != PIPE)
		{
			if (temp->token == COMMAND)
			{
				save_cmd->content = ft_strjoin(save_cmd->content, " ");
				save_cmd->content
					= ft_strjoin(save_cmd->content, temp->content);
				temp->flag_delete = 1;
			}
			if (temp->flag_delete == 1)
				break ;
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		if (temp->flag_delete == 1)
			break ;
	}
	del_node(list);
}

void	regroup_command(t_list *list)
{
	t_list	*temp;
	t_list	*save_cmd;

	temp = list;
	save_cmd = NULL;
	while (temp)
	{
		if (temp->token == COMMAND)
		{
			save_cmd = temp;
			break ;
		}
		temp = temp->next;
	}
	if (save_cmd)
		regroup_command_2(list, save_cmd);
}
