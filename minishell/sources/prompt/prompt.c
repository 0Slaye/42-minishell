/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/22 14:19:54 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

char	*readline_handler(char *value)
{
	char	*line_read;

	line_read = readline(value);
	if (line_read && line_read[0] != ""[0])
		add_history(line_read);
	return (line_read);
}

void	prompt(char *value, t_program *program)
{
	char	*line_read;

	while (TRUE)
	{
		line_read = readline_handler(value);
		if (line_read && line_read[0] != ""[0])
		{
			program->lexer = lexer(line_read, program);
			free(line_read);
			if (program->lexer)
				program->ast = ast(program->lexer);
			if (program->ast && program->lexer)
				interpreter(program->ast, program);
			if (program->lexer)
				free_lexer(program->lexer);
			if (program->ast)
				free_tree(program->ast);
		}
		else if (line_read != NULL)
			free(line_read);
	}
}
