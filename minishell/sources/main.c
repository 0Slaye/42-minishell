/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:20 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	main(int argc, char **argv, char **envp)
{
	t_program	*program;

	program = ft_calloc(1, sizeof(t_program));
	if (!program)
		return (1);
	program->argc = argc;
	program->argv = argv;
	program->envp = envp;
	program->exit = 0;
	program->ast = 0;
	prompt("minishell$ ", program);
	return (free(program), 0);
}
