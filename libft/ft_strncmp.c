/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:07 by momox             #+#    #+#             */
/*   Updated: 2023/09/18 19:45:17 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && i != len - 1 && s1[i] != '\0')
	{
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
