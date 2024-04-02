/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_suffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:29 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/02 19:45:44 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*command_suffix(t_list *lexer, t_tree *node)
{
	t_list	*token;
	t_tree	*suffix;

	token = get_next_token(lexer);
	if (!token)
		return (NULL);
	while (lexer_get_type(token) == T_WORD)
	{
		consume_token(token);
		node->right = tree_new(T_WORD, lexer_get_value(token), NULL, NULL);
		node = node->right;
		token = get_next_token(lexer);
	}
	suffix = redirect(lexer);
	if (suffix)
		suffix->left = command_suffix(lexer, node);
	return (suffix);
}
