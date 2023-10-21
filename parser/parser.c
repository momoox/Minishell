/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:21:33 by momox             #+#    #+#             */
/*   Updated: 2023/10/12 17:02:14 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_data *data)
{
	if (check_whitespaces(data->input) == 1)
		return (0);
	if (check_quote(data->input, data) != '0')
		exit(0);
	if (check_char(data->input, data))
		exit(0);
	split_line(data);
	check_exit_var(data);
	env_check(data);
	if (ft_strchr(data->input, '|'))
		split_op(data, '|');
	if (ft_strchr(data->input, '<'))
		split_op(data, '<');
	if (ft_strchr(data->input, '>'))
		split_op(data, '>');
	if (!(ft_strncmp(data->input, "<<", 2)))
		split_hd(data->list);
	tokenize(data);
	check_quote_remove(data->list);
	cmd_tab(data);
	file_inout(data->list);
	tab_exec(data);
	return (0);
}

	// print_list(data->list);
	// print_list(data->list);
	// print_token(data->list);