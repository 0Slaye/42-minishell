/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 18:17:41 by uwywijas         ###   ########.fr       */
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
		add_history(line_read);
		r_lexer = lexer(line_read, program);
		free(line_read);
		if (!r_lexer)
			break ;
		r_ast = ast(r_lexer);
		if (!r_ast)
			break ;
		print_tree(r_ast, 0);
		free_lexer(r_lexer);
		free_tree(r_ast);
		//free(r_ast);
	}
}
