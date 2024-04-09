/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:06:47 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/09 17:40:06 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	free_exit(t_program *program, int status)
{
	if (program->lexer)
		free_lexer(program->lexer);
	if (program->ast)
		free_tree(program->ast);
	if (program->pipelvl != 0)
		free(program);
	exit(status);
}
