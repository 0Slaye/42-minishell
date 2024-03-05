/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:02:51 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/05 12:50:09 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	get_simple_quotes_length(char *line)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	while (line[++i] != '\'' && line[i] != '\0')
		result++;
	if (line[i] == '\0')
		return (-1);
	return (result);
}
