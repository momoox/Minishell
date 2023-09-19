/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:43:09 by momox             #+#    #+#             */
/*   Updated: 2023/09/19 16:25:05 by momox            ###   ########.fr       */
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

void	print_tab(t_data *data)
{
	// int	i;
	int	u;

	// i = 0;
	u = 0;
	while (data->exec && data->exec[1].cmd[u])
	{
		printf("tab line = %s\n", data->exec[1].cmd[u]);
		// i++;
		u++;
	}
}
