/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:37:20 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/08 16:08:21 by uwywijas         ###   ########.fr       */
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

int	quotes_case_utils_hashmap(char *value, char *result, int *i, int *offset)
{
	int	*hashmap;

	hashmap = ft_hashmap(value);
	if (!hashmap)
		return (1);
	if (hashmap[*i] == T_S_QUOTE)
	{
		while (hashmap[++(*i)] != T_S_QUOTE)
			result[++(*offset)] = value[*i];
		(*i)++;
	}
	else if (hashmap[*i] == T_D_QUOTE)
	{
		while (hashmap[++(*i)] != T_D_QUOTE)
			result[++(*offset)] = value[*i];
		(*i)++;
	}
	return (free(hashmap), 0);
}

int	quotes_case_util(char *value, char *result, int *i, int *offset)
{
	if (value[*i + 1] == '\0')
		return (result[++(*offset)] = value[*i], 1);
	if (value[*i] == S_QUOTE && value[*i + 1] == S_QUOTE)
		*i += 1;
	else if (value[*i] == D_QUOTE && value[*i + 1] == D_QUOTE)
		*i += 1;
	else
		result[++(*offset)] = value[*i];
	return (0);
}
