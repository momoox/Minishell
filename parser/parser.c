/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:21:33 by momox             #+#    #+#             */
/*   Updated: 2023/09/24 20:01:35 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_data *data)
{
	// check_quote(data);
	split_line(data);
	env_check(data);
	if (ft_strchr(data->input, '|'))
		split_op(data, '|');
	if (ft_strchr(data->input, '<'))
		split_op(data, '<');
	if (ft_strchr(data->input, '>'))
		split_op(data, '>');
	if (!(ft_strncmp(data->input, "<<", 2) == 0))
		split_hd(data->list);
	tokenize(data);
	cmd_tab(data);
	file_inout(data->list);
	// print_list(data->list);
	tab_exec(data);
	//print_tab(data);
	//print_token(data->list);
	//envoyer data
	return (0);
}
	//gérer les guillemets
	//fout pas toute la ligne dans la struct pour exec
	//renvoyer une erreur quand parenthèse
	//pour entrée term = stdin NULL pareil pour sortie je crois à vérifier