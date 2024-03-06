/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:12:08 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/06 17:36:10 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"
#include "errors.h"

int	setup_hashmap(char *line, int *hashmap)
{
	int	i;

	i = -1;
	while (++i < (int) ft_strlen(line))
		hashmap[i] = 0;
	if (setup_quotes(line, hashmap) != 0)
		return (printf(ER_LEXER_QUOTE), 1);
	return (0);
}

int	*ft_hashmap(char *line)
{
	int	*hashmap;

	hashmap = malloc(sizeof(int) * ft_strlen(line));
	if (!hashmap)
		return (NULL);
	if (setup_hashmap(line, hashmap) != 0)
		return (free(hashmap), NULL);
	return (hashmap);
}
