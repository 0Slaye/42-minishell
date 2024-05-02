/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:06:47 by uwywijas          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/23 18:40:43 by uwywijas         ###   ########.fr       */
=======
/*   Updated: 2024/04/25 16:37:09 by tal-yafi         ###   ########.fr       */
>>>>>>> slowpoke
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
	if (program->envp)
		ft_array_cleaner((void **)program->envp, ft_array_len(program->envp));
	if (program->pipelvl != 0)
		free(program);
	exit(status);
}
