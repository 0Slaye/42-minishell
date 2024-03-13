/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater_expender_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:37:20 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/13 18:49:33 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	get_list_value_length(t_list **list)
{
	int		length;
	t_list	*holder;

	holder = *list;
	length = ft_lstsize(*list) - 1;
	while (*list)
	{
		if (lexer_get_type(*list) == 1)
			length += ft_strlen(lexer_get_value(*list));
		*list = (*list)->next;
	}
	*list = holder;
	return (length);
}
