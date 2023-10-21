/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:07:04 by momox             #+#    #+#             */
/*   Updated: 2023/10/11 23:36:31 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	data->input = NULL;
	data->parsed_line = NULL;
	data->env = NULL;
	data->flag_unlink = 0;
	data->list = NULL;
	data->nb_exec = 0;
	data->exit_code = 0;
}

void	reinit(t_data *data)
{
	data->input = NULL;
	data->parsed_line = NULL;
	data->flag_unlink = 0;
	data->list = NULL;
	data->nb_exec = 0;
}
