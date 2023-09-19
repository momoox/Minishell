/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:13:11 by momox             #+#    #+#             */
/*   Updated: 2023/09/18 19:47:19 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_here_doc(char *bp, t_data *data)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(".here_doc_minishell_tro_bien", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		// signal(SIGINT, sig_heredoc);
		line = readline("heredoc> ");
		ft_putendl_fd(line, fd);
		if (!(ft_strncmp(line, bp, ft_strlen(line) + ft_strlen(bp)))
			|| line == NULL)
			break ;
		free(line);
	}
	close(fd);
	unlink(".here_doc_minishell_tro_bien");
	data->flag_unlink = 1;
	//avoir un flag pour savoir si unlink et oliv unlink
	//ctrl c fonctionne pas, sort de heredoc
	free(line);
}

void	tokenize(t_data *data)
{
	t_list	*temp;

	temp = data->list;
	while (temp)
	{
		if (!(ft_strncmp(temp->content, "|", 1)))
			temp->token = PIPE;
		else if (!(ft_strncmp(temp->content, "<<", 2)))
			ft_here_doc(temp->next->content, data);
		else if (!(ft_strncmp(temp->content, ">>", 2)))
			temp->token = REDIR_APPEND;
		else if (!(ft_strncmp(temp->content, "<", 1)))
			temp->token = REDIR_IN;
		else if (!(ft_strncmp(temp->content, ">", 1)))
			temp->token = REDIR_OUT;
		else if (temp->prev
			&& (temp->prev->token == REDIR_IN
				|| temp->prev->token == REDIR_OUT
				|| temp->prev->token == REDIR_APPEND))
			temp->token = FILES;
		else
			temp->token = COMMAND;
		temp = temp->next;
	}
}
