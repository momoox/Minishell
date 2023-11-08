/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:53:37 by oliove            #+#    #+#             */
/*   Updated: 2023/11/06 00:53:42 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "util_exec.h"


void	init_data_shell(t_data *data)
{
	data->exec->shell->hold_pwd = ft_strdup_pipe(ft_my_var(data, "OLDPWD"));
	data->exec->shell->cwd = ft_strdup_pipe(ft_my_var(data, "PWD"));
	data->exec->shell->pwd = ft_strdup_pipe(ft_my_var(data, "PWD"));
	
}

