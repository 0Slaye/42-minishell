/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:25 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 17:43:54 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*piped_command(t_list *lexer)
{
	t_list	*token;

	token = get_next_token(lexer);
	if (!token)
		return (NULL);
	if (lexer_get_type(token) == T_PIPE)
	{
		consume_token(token);
		return (tree_new(G_PIPE, NULL, simple_command(lexer), \
		piped_command(lexer)));
	}
	return (NULL);
}
