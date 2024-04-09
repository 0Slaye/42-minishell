/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/09 14:47:09 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	execute(t_program *program, t_tree *node, int ifd, int ofd, int lvl)
{
	int	id;
	int	id2;
	int	fds[2];

	if (!node)
	{
		if (ifd != STDIN_FILENO)
			close(ifd);
		if (ofd != STDOUT_FILENO)
			close(ofd);
		exit(EXIT_SUCCESS);
	}
	if (node->type == T_PIPE)
	{
		pipe(fds);
		id = fork();
		if (id == 0)
		{
			if (node->right && !node->right->right)
			{
				close(fds[0]);
				if (ofd != STDOUT_FILENO)
					close(ofd);
				execute(program, node->right->left, ifd, fds[1], lvl + 1);
			}
			else
			{
				close(fds[0]);
				if (ofd != STDOUT_FILENO)
					close(ofd);
				execute(program, node->right, ifd, fds[1], lvl + 1);
			}
		}
		id2 = fork();
		if (id2 == 0)
		{
			close(fds[1]);
			if (ifd != STDIN_FILENO)
				close(ifd);
			if (lvl != 0)
				execute(program, node->left, fds[0], ofd, lvl);
			else if (lvl == 0 && !node->right)
			{
				close(fds[0]);
				execute(program, node->left, ifd, ofd, lvl);
			}
			else
				execute(program, node->left, fds[0], ofd, lvl);
		}
		close(fds[0]);
		close(fds[1]);
		if (ifd != STDIN_FILENO)
			close(ifd);
		if (ofd != STDOUT_FILENO)
			close(ofd);
		waitpid(id2, &program->exit, 0);
	}
	else
	{
		dup2(ifd, STDIN_FILENO);
		if (ifd != STDIN_FILENO)
			close(ifd);
		dup2(ofd, STDOUT_FILENO);
		if (ofd != STDOUT_FILENO)
			close(ofd);
		path_execve(node->value, get_cmd_option(node), program->envp);
		exit(EXIT_SUCCESS);
	}
}

int	interpreter(t_tree *ast, t_program *program)
{
	execute(program, ast, 0, 1, 0);
	wait(NULL);
	return (0);
}
