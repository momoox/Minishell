/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:17:48 by momox             #+#    #+#             */
/*   Updated: 2023/10/25 21:40:25 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*erase_quote(char *str, int *index_tab)
{
	int		i;
	int		u;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	u = 0;
	while (index_tab[u] != -1)
		u++;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1) - u);
	u = 0;
	while (str[i])
	{
		if (i == index_tab[u])
		{
			u++;
			i++;
		}
		if (str[i])
			new[k++] = str[i++];
	}
	new[k] = '\0';
	free(str);
	return (new);
}
