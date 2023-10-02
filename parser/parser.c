/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:21:33 by momox             #+#    #+#             */
/*   Updated: 2023/10/02 02:42:03 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_data *data)
{
	if (check_quote(data->input) != '0')
		exit(0);
	split_line(data);
	env_check(data);
	if (ft_strchr(data->input, '|'))
		split_op(data, '|');
	if (ft_strchr(data->input, '<'))
		split_op(data, '<');
	if (ft_strchr(data->input, '>'))
	{
		printf("split >\n");
		split_op(data, '>');
	}
	if (!(ft_strncmp(data->input, "<<", 2) == 0))
		split_hd(data->list);
	tokenize(data);
	cmd_tab(data);
	file_inout(data->list);
	tab_exec(data);
	print_list(data->list);
	return (0);
}
	// print_exec(data);
	//print_token(data->list);
	//envoyer data
	//gérer les guillemets
	//renvoyer une erreur quand parenthèse
	//pour entrée term = stdin NULL pareil pour sortie