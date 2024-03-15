/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/15 16:50:15 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../sources/libft/libft.h"
# include "tokens.h"

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_input;

// Prompt
void	prompt(char *value, t_input *input);

// Lexer
t_list	**lexer(char *line, t_input *input);
int		lexer_get_type(t_list *list);
int		lexer_formater(t_list **lexer);
int		spaces_before_case(t_list **lexer);
int		spaces_after_case(t_list **lexer);
int		useless_quotes_case(t_list **lexer);
char	*lexer_expender(char *value, char **envp);
void	lst_update_type(t_list *first, t_list *second, int type);
char	*lexer_get_value(t_list *list);
t_token	*get_token(int type, char *value);
char	*get_word(int *hashmap, char *line);
void	free_lexer(t_list **lexer);
void	lfree(void *token);
void	show_lexer(t_list **lexer);
int		*ft_hashmap(char *line);
void	show_hashmap(int *hashmap, int length);
int		setup_quotes(char *line, int *hashmap);
void	setup_tokens(char *line, int *hashmap);
t_list	**split_command(char *command);
int		get_list_value_length(t_list **list);
int		clean_quotes_case(t_list **lexer);
int		is_simple_quoted(char *value, int *hashmap, int is_quoted, int i);
int		add_to_list(t_list **list, char *value, int type);
int		add_var_to_list(t_list **list, char *value, char **envp, int *i);
char	*get_expend_value(char *value, char **envp);
int		list_return_selector(t_list **list);
void	replace_token_by_ascii(char *value);
void	update_token_by_ascii(char *value);

#endif