/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momox <momox@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:38:23 by mgeisler          #+#    #+#             */
/*   Updated: 2023/10/02 21:57:59 by momox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// # include <unistd.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <readline/readline.h>
// # include <readline/history.h>
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

enum	e_token
{
	PIPE = 0,
	FILES = 1,
	COMMAND = 2,
	REDIR_IN = 3,
	REDIR_APPEND = 4,
	REDIR_OUT = 5,
	REDIR_HERE_DOC = 6,
};

typedef struct s_list
{
	char			*content;
	char			**cmd;
	int				flag_delete;
	enum e_token	token;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_data	*data;
}					t_list;

typedef struct s_exec
{
	t_list			*stdin;
	char			**cmd;
	t_list			*stdout;
}					t_exec;

typedef struct s_data
{
	int				flag_unlink;
	char			*input;
	char			**env;
	char			**parsed_line;
	t_exec			*exec;
	t_list			*list;
}					t_data;

/* LIBFT */
char	*ft_strchr(const char *str, int search);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t len);
void	tab_env(t_data *data, char **env);
char	*ft_substr(char *s, int start, int len);
void	env_check(t_data *data);
int		is_env(char *arg);
int		env_pos(char *arg);
char	*get_env(char *arg, int len);
char	*replace_env(char *arg, char *replace);
char	*identify_replace(t_data *data, char *var_env);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char *s, char c);
void	file_inout(t_list *list);
char	**ft_tabadd_back(char **tab, char *new_str);

/* main */
void	reader(t_data *data);

/* parser */
void	sig_handler(int signo);
void	sig_ignore(int signum);
void	sig_onoff(int i);
void	sig_hd(int signo);
int		parser(t_data *data);
int		check_char(char *str);
char	check_quote(char *str);
void	quote_remove(t_list *list);
char	is_between_quote(char *str, int index);
int		is_operator(char c);
void	ft_here_doc(char *bp, t_data *data);
int		split_op(t_data *data, char c);
void	split_line(t_data *data);
void	split_hd(t_list *list);
void	tokenize(t_data *data);
void	tab_exec(t_data *data);
void	cmd_tab(t_data *data);

/* split */
char	**ft_split_operators(char *s, char c);
char	**ft_split_whitespaces(char *s);

/* utils */
int		len_input(char *s);
void	print_tab(t_data *data);

/* whitespace */
int		ft_whitespace(char c);

/* list utils */
void	lstadd_front(t_list **first, t_list *new);
void	lstadd_back(t_list **first, t_list *new);
t_list	*ft_lstnew(char *str);
void	list_back(t_list *list);

/* list utils 2 */
void	ft_lstdel_here(t_list **first, t_list *delete);
void	ft_lstadd_here(t_list **lst, t_list *new);
int		size_list_string(t_list *list);

/* init_struct */
void	init_data(t_data *data);
void	reinit(t_data *data);

void	print_list(t_list *list);
void	print_exec(t_data *data);
void	print_tab(t_data *data);
void	printtab2(char **tab);
void	print_token(t_list *list);

#endif