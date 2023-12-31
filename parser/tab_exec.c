/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:38:20 by momox             #+#    #+#             */
/*   Updated: 2023/11/08 23:49:27 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*fonction file
open - close
redir in = file, O_RDONLY
redir out = file, O_WRONLY | O_CREAT | O_TRUNC, 0644
redir append = file, O_WRONLY | O_CREAT | O_APPEND, 0644
puis close*/

void	create_tab(t_mall *mall, t_data *data, t_list *temp, int i)
{
	while (temp && i < data->nb_exec)
	{
		while (temp && temp->token != PIPE)
		{
			if (temp->token == REDIR_IN)
				redir_in_manage(mall, data, temp);
			if (temp->token == COMMAND && data->exec[i].cmd == NULL)
				data->exec[i].cmd = temp->cmd;
			if (temp->token == REDIR_OUT)
				redir_out_manage(mall, data, temp);
			if (temp->token == REDIR_APPEND)
				redir_append_manage(mall, data, temp);
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

void	init_exec(t_mall *mall, t_data *data, int nb_pipe)
{
	int	i;

	i = 0;
	data->exec = malloc_plus_plus(&mall, sizeof(t_exec) * (nb_pipe + 1));
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

void	tab_exec(t_mall *mall, t_data *data)
{
	t_list	*temp;
	int		i;

	temp = data->list;
	i = 0;
	data->nb_exec = count_pipe(temp);
	init_exec(mall, data, data->nb_exec);
	create_tab(mall, data, temp, i);
}
