/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_operators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:22:16 by momox             #+#    #+#             */
/*   Updated: 2023/09/17 20:30:49 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	count_op(char const *s, char c)
{
	size_t	i;
	size_t	words;
	int		op;

	i = 0;
	words = 0;
	op = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == 0 || s[i + 1] == c))
			words++;
		if (s[i] == c && s[i + 1] == c)
		{
			op++;
			i++;
		}
		else if (s[i] == c)
			op++;
		i++;
	}
	return (words + op);
}

size_t	lenword_op(const char *s, size_t i, char c)
{
	size_t	len;
	int		limit;

	len = 0;
	limit = 2;
	if (s[i] == c)
	{
		while (s[i] && s[i] == c && limit--)
			i++;
		return (i);
	}
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*cpyword_op(char *s, size_t *i, char c, size_t len)
{
	char	*str;
	size_t	u;

	(void)c;
	u = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len)
	{
		str[u++] = s[(*i)++];
		len--;
	}
	str[u] = '\0';
	return (str);
}

// char	*cpyword_op(char *s, size_t *i, char c, size_t len)
// {
// 	char	*str;
// 	size_t	u;

// 	u = 0;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len] = 0;
// 	if (s[*i] == c)
// 	{
// 		str[u++] = c;
// 		(*i)++;
// 		return (str);
// 	}
// 	while (len)
// 	{
// 		str[u++] = s[(*i)++];
// 		len--;
// 	}
// 	str[u] = '\0';
// 	return (str);
// }

char	**freeall_op(char **tab)
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

char	**ft_split_operators(char *s, char c)
{
	size_t		i;
	size_t		j;
	char		**tab;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (count_op(s, c) + 1));
	if (!tab)
		return (0);
	while (j < count_op(s, c))
	{
		tab[j++] = cpyword_op(s, &i, c, lenword_op(s, i, c));
		if (!tab[j - 1])
			return (freeall_op(tab));
	}
	tab[j] = 0;
	return (tab);
}
