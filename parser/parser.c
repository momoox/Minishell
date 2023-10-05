/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliove <olivierliove@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:21:33 by momox             #+#    #+#             */
/*   Updated: 2023/10/05 18:38:31 by oliove           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_data *data)
{
	if (check_quote(data->input) != '0')
		exit(0);
	if (check_char(data->input))
		exit(0);
	split_line(data);
	// print_list(data->list);
	env_check(data);
	if (ft_strchr(data->input, '|'))
		split_op(data, '|');
	if (ft_strchr(data->input, '<'))
		split_op(data, '<');
	if (ft_strchr(data->input, '>'))
		split_op(data, '>');
	if (!(ft_strncmp(data->input, "<<", 2)))
		split_hd(data->list);
	// quote_remove(data->list);
	tokenize(data);
	cmd_tab(data);
	file_inout(data->list);
	tab_exec(data);
	// print_list(data->list);
	// print_exec(data);
	// print_token(data->list);
	return (0);
}
	//envoyer data
	//pour entrée term = stdin NULL pareil pour sortie