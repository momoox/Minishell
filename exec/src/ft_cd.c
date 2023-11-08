/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:53:37 by oliove            #+#    #+#             */
/*   Updated: 2023/11/08 15:47:43 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "util_exec.h"


int	chdir_errno_mod(char *path)
{
	if (errno == ESTALE)
		errno = ENOENT;
	errmsg_cmd("cd", path, strerror(errno), errno);
	return (0);
}

int	change_dir(t_data *data, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
		return (chdir_errno_mod(path));
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		errmsg_cmd("cd: error retrieving current directory",
			"getcwd: cannot access parent directories",
			strerror(errno), errno);
		ret = ft_strjoin_norml(data->exec->shell->cwd, "/");
		tmp = ret;
		ret = ft_strjoin_norml(tmp, path);
		free_tmp(tmp);
	}
	else
		ret = ft_strdup_pipe(cwd);
	printf("ch_dir ret = %s \n ", ret);
	update_wds(data, ret);
	return (1);
}

int	ft_cd2(t_data *data, char **args)
{
	char	*path;

	if (!args || !args[1] || ft_isspace(args[1][0]) || args[1][0] == '\0'
		|| ft_strncmp(args[1], "--", 3) == 0)
	{
		path = /*ft_my_var(data,"HOME");*/ get_env_var_value(data->env, "HOME");
		if (!path || *path == '\0' || ft_isspace(*path))
			return (errmsg_cmd("cd", NULL, "HOME not set", EXIT_FAILURE));
		return (!change_dir(data, path));
	}
	if (args[2])
		return (errmsg_cmd("cd", NULL, "too many arguments", EXIT_FAILURE));
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = /*ft_my_var(data, "OLDPWD");*/ get_env_var_value(data->env,
				"OLDPWD");
		if (!path)
			return (errmsg_cmd("cd", NULL, "OLDPWD not set", EXIT_FAILURE));
		return (!change_dir(data, path));
	}
	return (!change_dir(data, args[1]));
	// return (0);
}

