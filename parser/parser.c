/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:21:33 by momox             #+#    #+#             */
/*   Updated: 2023/11/04 21:03:58 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parser(t_data *data, t_mall *mall)
{
	if (check_whitespaces(data->input) == 1)
		return (0);
	if (check_quote(data->input, data) != '0')
		exit(0);
	if (check_char(data->input, data))
		exit(0);
	split_line(mall, data);
	check_exit_var(mall, data);
	env_check(mall, data);
	if (ft_strchr(data->input, '|'))
		split_op(mall, data, '|');
	if (ft_strchr(data->input, '<'))
		split_op(mall, data, '<');
	if (ft_strchr(data->input, '>'))
		split_op(mall, data, '>');
	if (!(ft_strncmp(data->input, "<<", 2)))
		split_hd(mall, data->list);
	tokenize(data);
	check_quote_remove(mall, data->list);
	print_list(data->list);
	cmd_tab(mall, data);
	file_inout(data->list);
	tab_exec(mall, data);
	return (0);
}

	// print_exec(data);
	// print_list(data->list);
	// print_token(data->list);