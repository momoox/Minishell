/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:38:20 by momox             #+#    #+#             */
/*   Updated: 2023/09/17 22:09:13 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_exec(t_data *data, int nb_pipe)
{
	int	i;

	i = 0;
	data->exec = malloc(sizeof(t_exec) * (nb_pipe + 1));
	while (i < nb_pipe)
	{
		data->exec[i].cmd = NULL;
		data->exec[i].stdin = NULL;
		data->exec[i].stdout = NULL;
		i++;
	}
}

int	count_pipe(t_list *list)
{
	t_list	*temp;
	int		nb_pipe;

	temp = list;
	nb_pipe = 0;
	while (temp)
	{
		if (temp->token == PIPE)
			nb_pipe++;
		temp = temp->next;
	}
	return (nb_pipe + 1);
}

void	tab_exec(t_data *data)
{
	t_list	*temp;
	int		i;
	int		nb_pipe;

	temp = data->list;
	i = 0;
	nb_pipe = count_pipe(temp);
	init_exec(data, nb_pipe);
	while (temp && i < nb_pipe)
	{
		if (temp->token == REDIR_IN)
			data->exec[i].stdin = temp;
		if (temp->token == COMMAND)
			data->exec[i].cmd = data->list->cmd;
		if (temp->token == REDIR_OUT || temp->token == REDIR_APPEND)
			data->exec[i].stdout = temp;
		if (temp->token == PIPE && data->exec[i].stdin == NULL)
			data->exec[i].stdin = temp;
		if (temp->token == PIPE && data->exec[i].stdout == NULL)
			data->exec[i].stdout = temp;
		temp = temp->next;
		i++;
	}
}
