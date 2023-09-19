/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:59:38 by momox             #+#    #+#             */
/*   Updated: 2023/09/18 18:15:29 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	count(char *s)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (ft_whitespace(s[i]) == 0
			&& (s[i + 1] == 0 || ft_whitespace(s[i + 1])))
			words++;
		i++;
	}
	return (words);
}

size_t	lenword(char *s, size_t i)
{
	size_t	len;

	len = 0;
	while (ft_whitespace(s[i]) == 1)
		i++;
	while (!ft_whitespace(s[i]) && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	*cpyword(char *s, size_t *i, size_t len)
{
	char	*str;
	size_t	u;

	u = 0;
	while (ft_whitespace(s[(*i)]))
		(*i)++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len)
	{
		str[u++] = s[(*i)++];
		len--;
	}
	str[u] = '\0';
	return (str);
}

char	**freeall(char **tab)
{
	size_t	j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split_whitespaces(char *s)
{
	size_t		i;
	size_t		j;
	char		**tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (count(s) + 1));
	if (!tab)
		return (0);
	while (j < count(s))
	{
		tab[j++] = cpyword(s, &i, lenword(s, i));
		if (!tab[j - 1])
			return (freeall(tab));
	}
	tab[j] = 0;
	return (tab);
}
