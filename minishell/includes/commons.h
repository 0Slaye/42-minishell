/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 13:19:14 by uwywijas         ###   ########.fr       */
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
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "../sources/libft/libft.h"
# include "tokens.h"

typedef struct s_program
{
	int		argc;
	char	**argv;
	char	**envp;
	int		exit;
	int		ast;
}	t_program;

typedef struct s_tree
{
	int		type;
	void	*left;
	void	*right;
	char	*value;
}	t_tree;

// Prompt
void	prompt(char *value, t_program *program);

// Lexer
t_token	*get_token(int type, char *value);
t_list	**lexer(char *line, t_program *program);
t_list	**split_command(char *command);
void	lst_update_type(t_list *first, t_list *second, int type);
void	free_lexer(t_list **lexer);
void	lfree(void *token);
void	show_lexer(t_list **lexer);
void	show_hashmap(int *hashmap, int length);
void	setup_tokens(char *line, int *hashmap);
void	replace_token_by_ascii(char *value);
void	update_token_by_ascii(char *value);
char	*lexer_get_value(t_list *list);
char	*get_word(int *hashmap, char *line);
char	*lexer_expender(char *value, t_program *program);
char	*get_expend_value(char *value, t_program *program);
int		lexer_get_type(t_list *list);
int		lexer_formater(t_list **lexer);
int		spaces_before_case(t_list **lexer);
int		spaces_after_case(t_list **lexer);
int		useless_quotes_case(t_list **lexer);
int		*ft_hashmap(char *line);
int		setup_quotes(char *line, int *hashmap);
int		get_list_value_length(t_list **list);
int		clean_quotes_case(t_list **lexer);
int		is_simple_quoted(char *value, int *hashmap, int is_quoted, int i);
int		add_to_list(t_list **list, char *value, int type);
int		add_var_to_list(t_list **list, char *value, t_program *program, int *i);
int		list_return_selector(t_list **list);
int		get_envp_var_length(char *str);

// Parser
t_tree	*ast(t_list **lexer, t_program *program);
t_tree	*command_line(t_list **lexer, t_program *program);
t_tree	*tree_new(int type, char *value, t_tree *left, t_tree *right);
t_tree	*command_prefix(t_list *lexer);
t_tree	*command_suffix(t_list *lexer, t_tree *node);
t_tree	*piped_command(t_list *lexer, t_program *program);
t_tree	*redirect(t_list *lexer);
t_tree	*simple_command(t_list *lexer, t_program *program);
t_list	*get_next_token(t_list *lexer);
t_tree	*get_last_prefix(t_tree *prefix);
void	print_tree(t_tree *tree, int n);
void	free_tree(t_tree *tree);
void	consume_token(t_list *token);
void	return_error(t_list *token);

// Interpreter
char	**get_cmd_option(t_tree *node);
int		interpreter(t_tree *ast, t_program *program);
int		cmd_execute(t_tree *node, t_program *program, int in_fd, t_list *pipe);
int		get_node_size(t_tree *node, int select);
t_list	*setup_pipes(t_tree *ast);
void	close_pipes(t_list *pipe);
void	per_cmd_nfound(char *cmd_name);

#endif