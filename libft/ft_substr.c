/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:02:40 by momox             #+#    #+#             */
/*   Updated: 2023/09/11 17:49:43 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			slen;

	slen = 0;
	i = 0;
	if (!s || start < 0)
		return (0);
	if (start >= ft_strlen(s))
		slen = 0;
	else
	{
		while (s[start + slen] != '\0' && slen < len)
			slen++;
	}
	str = malloc(sizeof(char) * (slen) + 1);
	if (!str)
		return (0);
	if (slen != 0)
	{
		while (s[start] != '\0' && i + 1 <= len)
			str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}


// char	*ft_substr(t_list *list, int start, int len)
// {
// 	t_list	*temp;
// 	char	*str;
// 	int		i;
// 	int		slen;

// 	slen = 0;
// 	i = 0;
// 	if (!temp->content || start < 0)
// 		return (-1);
// 	slen = is_env(list->bdata);
// 	str = malloc(sizeof(char) * (slen) + 1);
// 	while (temp)
// 	{
// 		while (temp->content[j])
// 		{
// 			if (j == i)
// 				break ;
// 			j++;
// 		}
// 		temp = temp->next;
// 	}
// 	while (i + 1 <= len)
// 		str[i++] = temp->content[start++];
// 	str[i] = '\0';
// 	return (str);
// }
