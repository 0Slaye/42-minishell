/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:18:42 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/08 15:43:59 by uwywijas         ###   ########.fr       */
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

int	quotes_case(t_list **lexer)
{
	char	*result;
	char	*value;
	int		i;
	int		offset;

	value = lexer_get_value(*lexer);
	result = ft_calloc(ft_strlen(value) + 1, sizeof(char));
	if (!result)
		return (1);
	i = -1;
	offset = -1;
	while (value[++i] != '\0')
	{
		if (quotes_case_util(value, result, &i, &offset) != 0)
			break ;
	}
	result[++offset] = '\0';
	((t_token *)(*lexer)->content)->value = result;
	free(value);
	return (0);
}

int	lexer_formater(t_list **lexer)
{
	t_list	*holder;

	holder = *lexer;
	while (*lexer)
	{
		if ((*lexer)->next)
			redirections_case(lexer);
		if (lexer_get_type(*lexer) == T_WORD && quotes_case(lexer) != 0)
			return (1);
		*lexer = (*lexer)->next;
	}
	*lexer = holder;
	return (0);
}
