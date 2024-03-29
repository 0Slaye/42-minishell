/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_geter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:21:58 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/29 16:11:50 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	lexer_get_type(t_list *list)
{
	if (!list)
		return (-1);
	return ((int)((t_token *) list->content)->type);
}

char	*lexer_get_value(t_list *list)
{
	if (!list)
		return (NULL);
	return ((char *)((t_token *) list->content)->value);
}
