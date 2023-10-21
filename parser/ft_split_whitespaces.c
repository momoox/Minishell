/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:59:38 by momox             #+#    #+#             */
/*   Updated: 2023/10/21 22:27:08 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count(char *s)
{
	int	i;
	int	words;

	if (s[0] && !s[1])
		return (1);
	words = 0;
	i = 1;
	while (s[i])
	{
		if (ft_whitespace(s[i]) 
			&& is_between_quote(s, i) == '0'
			&& !ft_whitespace(s[i - 1]))
			words++;
		i++;
	}
	words++;
	return (words);
}

int	lenword(char *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && is_between_quote(s, i) == '0' && ft_whitespace(s[i]))
		i++;
	while (s[i]
		&& (is_between_quote(s, i) != '0'
			|| (is_between_quote(s, i) == '0' && !ft_whitespace(s[i]))))
	{
		len++;
		i++;
	}
	return (len);
}

char	*cpyword(char *s, int *i, int len)
{
	char	*str;
	int		u;

	u = 0;
	while ((ft_whitespace(s[(*i)]) && is_between_quote(s, *i) == '0'))
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
	int	j;

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
	int		i;
	int		j;
	char	**tab;

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
