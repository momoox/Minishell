/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:07:04 by momox             #+#    #+#             */
/*   Updated: 2023/09/29 23:37:30 by momox            ###   ########.fr       */
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
}

void	reinit(t_data *data)
{
	data->input = NULL;
	data->parsed_line = NULL;
	data->flag_unlink = 0;
	data->list = NULL;
}