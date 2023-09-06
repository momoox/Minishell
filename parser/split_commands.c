/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:04:02 by momox             #+#    #+#             */
/*   Updated: 2023/09/06 16:01:23 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tokenize(t_data *data)
{
	t_list	*temp;

	temp = data->list;
	while (temp)
	{
		if (!(ft_strncmp(temp->content, "|", 1)))
			temp->token = PIPE;
		else if (!(ft_strncmp(temp->content, "<", 1)))
			temp->token = REDIR_IN;
		else if (!(ft_strncmp(temp->content, ">", 1)))
			temp->token = REDIR_OUT;
		else if (!(ft_strncmp(temp->content, ">>", 2)))
			temp->token = REDIR_APPEND;
		else if (temp->prev
			&& (temp->prev->token == REDIR_IN
				|| temp->prev->token == REDIR_OUT
				|| temp->prev->token == REDIR_APPEND))
			temp->token = FILES;
		else
			temp->token = COMMAND;
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

int	split_op(t_data *data, char c)
{
	int		i;
	t_list	*save;
	t_list	*temp;

	temp = data->list;
	while (temp)
	{
		save = temp;
		data->parsed_line = ft_split_operators(temp->content, c);
		i = -1;
		while (data->parsed_line[++i])
		{
			ft_lstadd_here(&temp,
				ft_lstnew(ft_strdup(data->parsed_line[i])));
			temp = temp->next;
		}
		temp = temp->next;
		ft_lstdel_here(&data->list, save);
	}
	//list_back(data->list);
	return (0);
}

void	split_line(t_data *data)
{
	int	i;

	i = -1;
	data->parsed_line = ft_split_whitespaces(data->input);
	while (data->parsed_line[++i])
		lstadd_back(&data->list, ft_lstnew(ft_strdup(data->parsed_line[i])));
	list_back(data->list);
}

//lui envoyer la liste chainee, un split qui split sur les |, <, >, et les met dans la liste chainee
//puis un split qui split sur les espaces et les met dans la liste chainee
//puis supprimer maillon non split pour le remplacer par un maillon split
