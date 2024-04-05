/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/05 18:12:14 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

char	*readline_handler(char *value)
{
	char	*line_read;

	line_read = readline(value);
	if (line_read[0] != ""[0])
		add_history(line_read);
	return (line_read);
}

void	prompt(char *value, t_program *program)
{
	char	*line_read;
	t_list	**r_lexer;
	t_tree	*r_ast;

	while (TRUE)
	{
		line_read = readline_handler(value);
		if (line_read[0] != ""[0])
		{
			r_lexer = lexer(line_read, program);
			free(line_read);
			r_ast = ast(r_lexer);
			if (r_lexer)
				free_lexer(r_lexer);
			if (r_ast)
				free_tree(r_ast);
		}
	}
}
