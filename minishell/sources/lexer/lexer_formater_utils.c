/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:37:20 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/08 15:43:33 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

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
