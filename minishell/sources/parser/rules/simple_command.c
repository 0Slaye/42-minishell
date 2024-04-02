/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/02 15:12:47 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*simple_command(t_list *lexer, t_program *program)
{
	t_list	*token;
	t_tree	*prefix;
	t_tree	*suffix;

	if (!lexer)
		return (NULL);
	prefix = command_prefix(lexer);
	if (prefix)
	{
		token = get_next_token(lexer);
		if (lexer_get_type(token) == T_WORD)
		{
			consume_token(token);
			suffix = command_suffix(lexer);
			if (suffix)
				return (tree_new(G_COMMAND, lexer_get_value(token), prefix, suffix));
			return (tree_new(G_COMMAND, lexer_get_value(token), prefix, NULL));
		}
		return (prefix);
	}
	else
	{
		token = get_next_token(lexer);
		if (lexer_get_type(token) == T_WORD)
		{
			consume_token(token);
			suffix = command_suffix(lexer);
			if (suffix)
				return (tree_new(G_COMMAND, lexer_get_value(token), NULL, suffix));
			return (tree_new(G_COMMAND, lexer_get_value(token), NULL, NULL));
		}
		else
		{
			suffix = command_suffix(lexer);
			if (suffix)
				return (suffix);
		}
	}
	return_error(get_next_token(lexer));
	return (program->ast = 1, NULL);
}
