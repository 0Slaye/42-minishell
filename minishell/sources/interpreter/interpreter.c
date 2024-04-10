/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/10 17:28:02 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	interpreter(t_tree *ast, t_program *program)
{
	program->pipelvl = 0;
	if (setup_heredocs(ast) != 0)
		return (1);
	execute_ast(program, ast, 0, 1);
	wait(NULL);
	program->pipelvl = 0;
	return (0);
}
