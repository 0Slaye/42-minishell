/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 19:08:16 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*prefix_handler(t_list *lexer, t_tree *prefix)
{
	t_list	*token;
	t_tree	*suffix;
	t_tree	*node;

	token = get_next_token(lexer);
	if (lexer_get_type(token) == T_WORD)
	{
		consume_token(token);
		node = tree_new(G_COMMAND, lexer_get_value(token), prefix, NULL);
		suffix = command_suffix(lexer, node);
		get_last_prefix(prefix)->left = suffix;
		return (node);
	}
	return (prefix);
}

t_tree	*simple_command(t_list *lexer, t_program *program)
{
	t_list	*token;
	t_tree	*prefix;
	t_tree	*suffix;
	t_tree	*node;

	if (lexer_get_type(lexer) == T_PIPE)
	{
		consume_token(lexer);
		lexer = lexer->next;
	}
	if (!lexer)
		return (NULL);
	prefix = command_prefix(lexer);
	if (prefix)
		return (prefix_handler(lexer, prefix));
	else
	{
		token = get_next_token(lexer);
		if (lexer_get_type(token) == T_WORD)
		{
			consume_token(token);
			node = tree_new(G_COMMAND, lexer_get_value(token), NULL, NULL);
			suffix = command_suffix(lexer, node);
			node->left = suffix;
			return (node);
		}
	}
	return_error(get_next_token(lexer));
	return (program->ast = 1, NULL);
}
