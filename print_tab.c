/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:43:09 by momox             #+#    #+#             */
/*   Updated: 2023/09/06 15:53:11 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	len_input(char *s)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == ' ')
// 		{
// 			len++;
// 			i++;
// 		}
// 		i++;
// 	}
// 	return (len + 1);
// }

void	print_tab(char **tab)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (tab[i])
		printf("tab line %d = %s\n", line++, tab[i++]);
}
