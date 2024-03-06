/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/06 18:08:34 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

t_list	**lexer(char *line, t_input *input)
{
	int	*hashmap;

	(void) input;
	hashmap = ft_hashmap(line);
	if (!hashmap)
		return (NULL);
	show_hashmap(hashmap, ft_strlen(line));
	return (free(hashmap), NULL);
}
