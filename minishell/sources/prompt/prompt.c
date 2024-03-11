/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/11 17:56:09 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

void	prompt(char *value, t_input *input)
{
	char	*line_read;

	while (TRUE)
	{
		line_read = readline(value);
		add_history(line_read);
		lexer(line_read, input);
		free(line_read);
	}
}
