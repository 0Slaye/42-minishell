/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:19:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/06 17:32:26 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

int	count_char(char *str, char c)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			result++;
	}
	return (result);
}

int	setup_quotes(char *line, int *hashmap)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == S_QUOTE)
		{
			if (ft_strchr(&line[i + 1], S_QUOTE) == 0)
				return (1);
			hashmap[i] = T_S_QUOTE;
			while (line[++i] != '\0' && line[i] != S_QUOTE)
				hashmap[i] = T_WORD;
			hashmap[i] = T_S_QUOTE;
		}
		else if (line[i] == D_QUOTE)
		{
			if (ft_strchr(&line[i + 1], D_QUOTE) == 0)
				return (1);
			hashmap[i] = T_D_QUOTE;
			while (line[++i] != '\0' && line[i] != D_QUOTE)
				hashmap[i] = T_WORD;
			hashmap[i] = T_D_QUOTE;
		}
	}
	return (0);
}
