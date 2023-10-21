/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:17:48 by momox             #+#    #+#             */
/*   Updated: 2023/10/21 22:27:39 by oliove           ###   ########.fr       */
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
