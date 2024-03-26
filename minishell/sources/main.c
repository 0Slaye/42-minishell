/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/26 16:29:55 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	main(int argc, char **argv, char **envp)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (1);
	program->argc = argc;
	program->argv = argv;
	program->envp = envp;
	program->exit = 0;
	prompt("minishell$ ", program);
	return (free(program), 0);
}
