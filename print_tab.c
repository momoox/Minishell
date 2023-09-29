/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:43:09 by momox             #+#    #+#             */
/*   Updated: 2023/09/24 21:20:33 by momox            ###   ########.fr       */
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

void	print_exec(t_data *data)
{
	int	u;

	u = 0;
	while (data->exec[0].cmd[u])
	{
		printf("tab line = %s\n", data->exec[0].cmd[u]);
		printf("struct = %s\n", data->exec[0].stdin->content);
		printf("struct = %s\n", data->exec[0].stdout->content);
		u++;
	}
	while (data->exec[1].cmd[u])
	{
		printf("tab line = %s\n", data->exec[1].cmd[u]);
		printf("struct = %s\n", data->exec[1].stdin->content);
		printf("struct = %s\n", data->exec[1].stdout->content);
		u++;
	}
}

void	print_tab(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = 2;
	printf("tab test\n");
	while (i < size)
	{
		printtab2(data->exec[i].cmd);
		i++;
	}
}

void	printtab2(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
	{
		printf("%s\n", tab[i]);
	}
}
