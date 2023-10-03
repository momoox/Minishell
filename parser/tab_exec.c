/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:38:20 by momox             #+#    #+#             */
/*   Updated: 2023/10/03 00:09:13 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_tab(t_data *data, t_list *temp, int i, int nb_pipe)
{
	while (temp && i < nb_pipe)
	{
		while (temp && temp->token != PIPE)
		{
			if (temp->token == REDIR_IN)
				data->exec[i].stdin_st = temp;
			if (temp->token == COMMAND && data->exec[i].cmd == NULL)
				data->exec[i].cmd = temp->cmd;
			if (temp->token == REDIR_OUT || temp->token == REDIR_APPEND)
				data->exec[i].stdout_st = temp;
			if (temp->token == PIPE && data->exec[i].stdin_st == NULL)
				data->exec[i].stdin_st = temp;
			if (temp->token == PIPE && data->exec[i].stdout_st == NULL)
				data->exec[i].stdout_st = temp;
			temp = temp->next;
		}
		if (temp && temp->token == PIPE)
		{
			data->exec[i + 1].stdin_st = temp;
			temp = temp->next;
		}
		i++;
	}
}

void	init_exec(t_data *data, int nb_pipe)
{
	int	i;

	i = 0;
	data->exec = malloc(sizeof(t_exec) * (nb_pipe + 1));
	while (i < nb_pipe)
	{
		data->exec[i].cmd = NULL;
		data->exec[i].stdin_st = NULL;
		data->exec[i].stdout_st = NULL;
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
	create_tab(data, temp, i, nb_pipe);
}
