/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_suffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:29 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 17:44:10 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*command_suffix(t_list *lexer)
{
	t_list	*token;
	t_tree	*suffix;

	token = get_next_token(lexer);
	if (!token)
		return (NULL);
	if (lexer_get_type(token) == T_WORD)
	{
		consume_token(token);
		suffix = tree_new(T_WORD, lexer_get_value(token), NULL, \
		command_suffix(lexer));
	}
	else
	{
		suffix = redirect(lexer);
		if (suffix)
			suffix->right = command_suffix(lexer);
	}
	return (suffix);
}
