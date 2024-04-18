/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/18 15:08:34 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	check_solo_cmds(t_program *program, t_tree *ast)
{
	t_tree	*node;

	if (ast->right)
		return (0);
	node = ast->left;
	if (ft_strncmp(node->value, "cd", ft_strlen(node->value)) == 0)
		return (ft_solo_cd(program, node), 1);
	if (ft_strncmp(node->value, "exit", ft_strlen(node->value)) == 0)
		return (program->pipelvl = -1, ft_exit(program, node), 1);
	return (0);
}

int	interpreter(t_tree *ast, t_program *program)
{
	program->pipelvl = 0;
	if (setup_heredocs(ast) != 0)
		return (1);
	if (check_solo_cmds(program, ast) != 0)
		return (0);
	execute_ast(program, ast, 0, 1);
	wait(NULL);
	program->pipelvl = 0;
	return (0);
}
