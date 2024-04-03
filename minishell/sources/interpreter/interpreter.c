/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/03 16:37:43 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	interpreter(t_tree *ast, t_program *program)
{
	int	result;

	while (ast)
	{
		result = cmd_execute(ast->left, program);
		if (result == 1)
			return (1);
		else if (result == 2)
			return (2);
		ast = ast->right;
	}
	wait(NULL);
	return (0);
}
