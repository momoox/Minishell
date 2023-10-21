/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:17:48 by momox             #+#    #+#             */
/*   Updated: 2023/10/10 18:49:59 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*erase_quote_2(char *str, char *new, int *index_tab, int index_len)
{
	int		i;
	int		u;
	int		k;

	i = 0;
	k = 0;
	u = 0;
	while (str[i])
	{
		if (i == index_tab[u])
		{
			u++;
			i++;
		}
		else
			new[k++] = str[i++];
	}
	new[ft_strlen(str) - index_len] = '\0';
	free(str);
	return (new);
}

char	*erase_quote(char *str, int *index_tab)
{
	int		u;
	int		index_len;
	char	*new;

	u = 0;
	index_len = 0;
	while (index_tab[u] != -1)
		u++;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1 - u));
	index_len = u;
	new = erase_quote_2(str, new, index_tab, index_len);
	return (new);
}
