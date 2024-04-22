/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:04:48 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/22 14:31:26 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	check_and_exec_builtin(t_program *program, t_tree *node)
{
	if (ft_strncmp(node->value, "echo", 4) == 0)
		return (ft_echo(node), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "cd", 2) == 0)
		return (ft_cd(program, node), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "pwd", 3) == 0)
		return (ft_pwd(), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "export", 6) == 0)
		return (ft_export(program, node), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "unset", 5) == 0)
		return (printf("%s\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "env", 3) == 0)
		return (ft_env(program), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "exit", 4) == 0)
		return (ft_exit(program, node));
	return ;
}
