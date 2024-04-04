/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 20:20:49 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*prefix_handler(t_list *lexer, t_tree *prefix, t_list *holder)
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
		consume_token(holder);
		return (node);
	}
	consume_token(holder);
	return (prefix);
}

t_list	*get_last_utoken(t_list *lexer)
{
	while (lexer)
	{
		if (lexer->next && lexer_get_type(lexer) != T_CONSUMED && lexer_get_type(lexer->next) == T_CONSUMED)
			return (lexer);
		else if (!lexer->next && lexer_get_type(lexer) != T_CONSUMED)
			return (lexer);
		lexer = lexer->next;
	}
	return (NULL);
}

t_tree	*simple_command(t_list *lexer, t_program *program)
{
	t_list	*token;
	t_tree	*prefix;
	t_tree	*suffix;
	t_tree	*node;
	t_list	*holder;

	holder = NULL;
	if (lexer_get_type(lexer) == T_PIPE)
	{
		if (!lexer->next)
			return (program->ast = 1, return_error(lexer), NULL);
		holder = lexer;
		lexer = lexer->next;
	}
	if (!lexer)
		return (NULL);
	prefix = command_prefix(lexer);
	if (prefix)
		return (prefix_handler(lexer, prefix, holder));
	else
	{
		token = get_next_token(lexer);
		if (lexer_get_type(token) == T_WORD)
		{
			consume_token(token);
			node = tree_new(G_COMMAND, lexer_get_value(token), NULL, NULL);
			suffix = command_suffix(lexer, node);
			node->left = suffix;
			consume_token(holder);
			return (node);
		}
	}
	if (program->ast != 1)
	{
		if (holder != NULL)
			return_error(holder);
		else
			return_error(get_last_utoken(lexer));
	}
	return (program->ast = 1, NULL);
}
