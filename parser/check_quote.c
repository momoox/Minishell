/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:19:24 by momox             #+#    #+#             */
/*   Updated: 2023/10/04 02:19:02 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	last_quote;

// char	where_is_quote(char *str)
// {
// 	char	quote;
// 	int		i;

// 	quote = '0';
// 	i = 0;
// 	if (!str)
// 		return (1);
// 	while (str[i] && i <= index)
// 	{
// 		if (quote == '0' && (str[i] == '\'' || str[i] == '\"'))
// 		{
// 			quote = str[i];
// 			return (quote);
// 		}
// 		i++;
// 	}
// 	return (quote);
// }

// void	quote_remove(t_list *list)
// {
// 	(void)list;
	
// }

char	is_between_quote(char *str, int index)
{
	char	quote;
	int		i;

	quote = '0';
	i = 0;
	if (!str)
		return (1);
	while (str[i] && i <= index)
	{
		if (quote == '0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote != '0' && str[i] == quote)
			quote = '0';
		i++;
	}
	return (quote);
}

char	check_quote(char *str)
{
	char	quote;
	int		i;

	quote = '0';
	i = 0;
	while (str[i])
	{
		if (quote == '0' && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (str[i] == quote)
			quote = '0';
		i++;
	}
	if (quote != '0')
		printf("Minishell : syntax error near unexpected token \'%c\'\n", quote);
	return (quote);
}
