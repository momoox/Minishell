/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:54:40 by oliove            #+#    #+#             */
/*   Updated: 2023/10/03 04:18:59 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/util.h"

int	check_path_slash(char *path, char **cmd)
{
	if (path == NULL || cmd[0][0] == '/' || (ft_strlen(cmd[0]) >= 2
			&& cmd[0][0] == '.' && cmd[0][1] == '/') || (ft_strlen(cmd[0]) >= 3
			&& cmd[0][0] == '.' && cmd[0][1] == '.' && cmd[0][2] == '/'))
		return (0);
	return (-1);
}

void	*ft_path_dir(char **cmd, char *path, int i)
{
	char	**path_directo;
	char	*name;
	char	*tmp;

	if (check_path_slash(path, cmd) == 0)
		return (cmd[0]);
	path_directo = ft_split(path, ':');
	while (path_directo[++i] != NULL)
	{
		tmp = ft_strjoin_pipe(path_directo[i], "/");
		name = ft_strjoin_pipe(tmp, cmd[0]);
		free(tmp);
		if (access(name, F_OK) == 0)
		{
			i = 0;
			while (path_directo[i])
				free(path_directo[i++]);
			free(cmd[0]);
			cmd[0] = name;
			return (name);
		}
		printf("ft_path_dir : name = [%s]\n",name);
		printf("ft_path_dir : cmd = [%s]\n",cmd[0]);
		free(name);
	}
	return (cmd);
}

int	file_o(char *file, int b)
{
	int	res;

	if (b == 0)
		res = open(file, O_RDONLY, 0777);
	if (b == 1)
		res = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (b == 2)
		res = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (res == -1)
		return (-1);
	return (res);
}
