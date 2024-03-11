/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/11 15:06:06 by uwywijas         ###   ########.fr       */
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
int		lexer_formater(t_list **lexer, char **envp);
int		spaces_before_case(t_list **lexer);
int		spaces_after_case(t_list **lexer);
int		useless_quotes_case(t_list **lexer);
int		expend_case(t_list **lexer, char **envp);
void	lst_update_type(t_list *first, t_list *second, int type);
void	lexer_expender(t_list **lexer, char **envp);
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

#endif