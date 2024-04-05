/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/05 19:21:51 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	execute(t_program *program, t_tree *node, int ifd, int ofd, int lvl)
{
	int	id;
	int	fds[2];

	if (!node)
		exit(EXIT_SUCCESS);
	if (node->type == T_PIPE)
	{
		if (pipe(fds) == -1)
			return (ft_putendl_fd(ER_PIPE_FUNC, 2));
		id = fork();
		if (id == -1)
			return (ft_putendl_fd(ER_FORK_FUNC, 2));
		if (id == 0)
			execute(program, node->right, ifd, fds[1], lvl + 1);
		else
			execute(program, node->left, fds[0], ofd, lvl);
	}
	else if (node)
	{
		id = fork();
		if (id == -1)
			return (ft_putendl_fd(ER_PIPE_FUNC, 2));
		if (id == 0)
			path_execve(node->value, get_cmd_option(node), program->envp);
		else if (lvl != 0)
			exit(EXIT_SUCCESS);
	}
}

int	interpreter(t_tree *ast, t_program *program)
{
	execute(program, ast, 0, 1, 0);
	wait(NULL);
	return (0);
}
