/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piped_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:25 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 19:12:44 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_list	*get_lpipe2(t_list **lexer)
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

t_tree	*piped_command(t_list *lexer, t_program *program)
{
	t_list	*token;

	token = get_lpipe2(&lexer);
	// if (lexer_get_type(token) == T_PIPE)
	// 	consume_token(token);
	if (!token)
		return (NULL);
	if (lexer_get_type(token) == T_PIPE)
	{
		if (!token->next && program->ast == 0)
			return (return_error(token), program->ast = 1, NULL);
		else if (!token->next && program->ast != 0)
			return (NULL);
		consume_token(token);
		return (tree_new(G_PIPE, NULL, simple_command(token->next, program), \
		piped_command(lexer, program)));
	}
	else
		return (simple_command(token, program));
	return (NULL);
}
