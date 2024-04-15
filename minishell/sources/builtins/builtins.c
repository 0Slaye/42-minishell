/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:04:48 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/15 18:13:25 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	check_and_exec_builtin(t_program *program, t_tree *node)
{
	if (ft_strncmp(node->value, "echo", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "cd", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "pwd", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "export", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "unset", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "env", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	if (ft_strncmp(node->value, "exit", ft_strlen(node->value)) == 0)
		return (printf("doing %s...\n", node->value), free_exit(program, EXIT_SUCCESS));
	return ;
}
