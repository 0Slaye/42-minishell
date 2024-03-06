/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/06 17:16:32 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

t_list	**lexer(char *line)
{
	int	*hashmap;

	hashmap = ft_hashmap(line);
	if (!hashmap)
		return (NULL);
	show_hashmap(hashmap, ft_strlen(line));
	return (free(hashmap), NULL);
}
