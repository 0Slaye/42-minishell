/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:25 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/27 18:40:49 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*piped_command(t_list *lexer)
{
	lexer = lexer_get_unsonsumed(lexer);
	if (!lexer)
		return (NULL);
	if (lexer_get_type(lexer) == T_PIPE)
	{
		((t_token *)lexer->content)->type = T_CONSUMED;
		return (tree_new(G_PIPE, NULL, simple_command(lexer), piped_command(lexer)));
	}
	return (NULL);
}
