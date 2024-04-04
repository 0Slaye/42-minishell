/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:54:07 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 19:44:30 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_list	*get_lpipe(t_list **lexer)
{
	t_list	*holder;
	t_list	*result;

	result = NULL;
	holder = *lexer;
	while (*lexer)
	{
		if (lexer_get_type(*lexer) == T_PIPE)
			result = *lexer;
		*lexer = (*lexer)->next;
	}
	*lexer = holder;
	if (result == NULL)
		return (*lexer);
	return (result);
}

t_tree	*command_line(t_list **lexer, t_program *program)
{
	t_tree	*tree;

	tree = tree_new(G_PIPE, NULL, simple_command(get_lpipe(lexer), program), \
	piped_command(*lexer, program));
	if (!tree || program->ast != 0)
		return (free_tree(tree), NULL);
	return (tree);
}
