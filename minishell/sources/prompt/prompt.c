/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/03 19:00:09 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	prompt(char *value, t_program *program)
{
	char	*line_read;
	t_list	**r_lexer;
	t_tree	*r_ast;

	while (TRUE)
	{
		line_read = readline(value);
		if (line_read[0] != ""[0])
			add_history(line_read);
		r_lexer = lexer(line_read, program);
		free(line_read);
		if (!r_lexer)
			return ;
		r_ast = ast(r_lexer, program);
		if (!r_ast && program->ast != 0)
			return (free_lexer(r_lexer));
		if (interpreter(r_ast, program) == 2)
			return (free_lexer(r_lexer), free_tree(r_ast), exit(EXIT_SUCCESS));
		free_lexer(r_lexer);
		free_tree(r_ast);
		program->ast = 0;
	}
}
