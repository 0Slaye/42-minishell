/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:18:42 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/08 14:31:41 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	lst_update_type(t_list *first, t_list *second, int type)
{
	t_list	*holder;

	holder = second->next;
	ft_lstdelone(second, &lfree);
	((t_token *) first->content)->type = type;
	first->next = holder;
}

void	lexer_formater(t_list **lexer)
{
	t_list	*holder;

	holder = *lexer;
	while (*lexer)
	{
		if ((*lexer)->next)
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
		*lexer = (*lexer)->next;
	}
	*lexer = holder;
}
