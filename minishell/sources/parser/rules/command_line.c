/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:54:07 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/02 14:58:15 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*command_line(t_list **lexer, t_program *program)
{
	t_tree	*tree;

	tree = tree_new(G_PIPE, NULL, simple_command(*lexer, program), \
	piped_command(*lexer, program));
	if (!tree || program->ast != 0)
		return (free_tree(tree), NULL);
	return (tree);
}
