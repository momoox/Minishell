/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:24 by momox             #+#    #+#             */
/*   Updated: 2023/09/28 15:39:31 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	is_between_quote(char *str, int index)
{
	char	quote;
	int		i;

	quote = '0';
	i = 0;
	while (str[i] && i != index)
	{
		if (str[i] == '\'' || str[i] == '\"')
			quote = str[i];
		else if (quote != '0' && (str[i] == '\'' || str[i] == '\"'))
			quote = '0';
		i++;
	}
	return (quote);
}

char	check_quote(char *str, int index)
{
	char	quote;
	int		i;

	quote = '0';
	i = 0;
	while (str[i] && i != index)
	{
		if (str[i] == '\'' || str[i] == '\"')
			quote = str[i];
		else if (quote != '0' && (str[i] == '\'' || str[i] == '\"'))
			quote = '0';
		i++;
	}
	if (quote != '0')
		printf("Minishell : syntax error near unexpected token `''\n");
	return (quote);
}
