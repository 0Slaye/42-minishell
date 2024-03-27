/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/27 18:40:08 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*simple_command(t_list *lexer)
{
	lexer = lexer_get_unsonsumed(lexer);
	if (!lexer)
		return (NULL);
	if (lexer_get_type(lexer) == T_WORD)
	{
		((t_token *)lexer->content)->type = T_CONSUMED;
		return (tree_new(G_COMMAND, lexer_get_value(lexer), NULL, NULL));
	}
	return (NULL);
}
