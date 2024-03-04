/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/04 18:02:50 by uwywijas         ###   ########.fr       */
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

void	prompt(char *value);
t_list	**lexer(char *line);
int		is_token(char *start, char *token);
int		get_word_lenght(char *line, int type);
void	show_lexing(t_list **lexing);
void	free_lexing(t_list **lexing);

#endif