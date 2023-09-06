/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:38:23 by mgeisler          #+#    #+#             */
/*   Updated: 2023/09/06 15:48:40 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>

enum	e_token
{
	PIPE = 0,
	FILES = 1,
	COMMAND = 2,
	REDIR_IN = 3,
	REDIR_APPEND = 4,
	REDIR_OUT = 5,
};

typedef struct s_list
{
	char			*content;
	enum e_token	token;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	char			*input;
	char			**parsed_line;
	t_list			*list;
}					t_data;

/* LIBFT */
char	*ft_strdup(char *src);
int		ft_strncmp(char *s1, char *s2, size_t len);

/* main */
void	reader(t_data *data);

/* parser */
int		parser(t_data *data);
int		split_op(t_data *data, char c);
void	split_line(t_data *data);
void	tokenize(t_data *data);

/* split */
char	**ft_split_operators(char *s, char c);
char	**ft_split_whitespaces(char *s);

/* utils */
int		len_input(char *s);
char	*ft_strchr(const char *str, int search);
void	print_tab(char **tab);

/* ft_strdup */
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);

/* whitespace */
int		whitespace(char c);

/* list utils */
void	lstadd_front(t_list **first, t_list *new);
void	lstadd_back(t_list **first, t_list *new);
t_list	*ft_lstnew(char *str);
void	list_back(t_list *list);

/* list utils 2 */
void	ft_lstdel_here(t_list **first, t_list *node_to_delete);
void	ft_lstadd_here(t_list **lst, t_list *new);

/* init_struct */
void	init_data(t_data *data);

void	print_list(t_list *list);
void	print_list_token(t_list *list);

#endif