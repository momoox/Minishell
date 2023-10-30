/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:15:35 by oliove            #+#    #+#             */
/*   Updated: 2023/10/30 14:54:17 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_home(void)
{
	const char	*home = getenv("HOME");

	if (home)
		printf("chdir(%s) = %d\n", home, chdir(home));
}

int	ft_cd(t_data *data, char *path)
{
	t_exec	*cmd;

	cmd = data->exec;
	if (!cmd->cmd[1])
		cd_home();
	if (cmd->cmd[1])
	{
		if (!strcmp(cmd->cmd[1], "~"))
			cd_home();
		else
			printf("chdir(%s) = %d\n", cmd->cmd[1], chdir(cmd->cmd[1]));
	}
	else
	{
		fprintf(stderr, "usage: cd <directory>\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
