/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:18:42 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/18 15:04:20 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	redirections_case(t_list **lexer)
{
	if (lexer_get_type(*lexer) == T_SL_REDIRECTION)
	{
		if (lexer_get_type((*lexer)->next) == T_SL_REDIRECTION)
			lst_update_type(*lexer, (*lexer)->next, T_DL_REDIRECTION);
	}
	else if (lexer_get_type(*lexer) == T_SR_REDIRECTION)
	{
		if (lexer_get_type((*lexer)->next) == T_SR_REDIRECTION)
			lst_update_type(*lexer, (*lexer)->next, T_DR_REDIRECTION);
	}
}

int	lexer_formater(t_list **lexer)
{
	t_list	*holder;

	holder = *lexer;
	while (*lexer)
	{
		if ((*lexer)->next)
			redirections_case(lexer);
		if (lexer_get_type(*lexer) == T_WORD && useless_quotes_case(lexer) != 0)
			return (1);
		if (lexer_get_type(*lexer) == T_WORD && clean_quotes_case(lexer) != 0)
			return (1);
		if (lexer_get_type(*lexer) == T_WORD)
			update_token_by_ascii(lexer_get_value(*lexer));
		*lexer = (*lexer)->next;
	}
	*lexer = holder;
	return (0);
}
