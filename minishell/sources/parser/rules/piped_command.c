/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:25 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/02 18:24:39 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*piped_command(t_list *lexer, t_program *program)
{
	t_list	*token;

	token = get_next_token(lexer);
	if (!token)
		return (NULL);
	if (lexer_get_type(token) == T_PIPE)
	{
		if (!token->next && program->ast == 0)
			return (return_error(token), program->ast = 1, NULL);
		else if (!token->next && program->ast != 0)
			return (NULL);
		consume_token(token);
		return (tree_new(G_PIPE, NULL, simple_command(lexer, program), \
		piped_command(lexer, program)));
	}
	return (NULL);
}
