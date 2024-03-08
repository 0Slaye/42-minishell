/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:17:42 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/08 16:22:31 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	spaces_before_case(t_list **lexer)
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
		if (i == 0 && value[i] == ' ')
		{
			while (value[++i] != '\0' && value[i] == ' ')
				;
		}
		result[++offset] = value[i];
	}
	result[++offset] = '\0';
	((t_token *)(*lexer)->content)->value = result;
	return (free(value), 0);
}

int	count_char_without(char *value, char c)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (value[++i] != '\0')
	{
		if (value[i] != c)
			result++;
	}
	return (result);
}

int	spaces_after_case(t_list **lexer)
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
		if (count_char_without(&value[i], ' ') == 0)
			break ;
		result[++offset] = value[i];
	}
	result[++offset] = '\0';
	((t_token *)(*lexer)->content)->value = result;
	return (free(value), 0);
}
