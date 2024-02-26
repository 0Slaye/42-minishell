/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:33:18 by uwywijas          #+#    #+#             */
/*   Updated: 2024/02/26 15:10:11 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	prompt(void)
{
	char	*line_read;

	while (TRUE)
	{
		line_read = readline(PROMPT);
		add_history(line_read);
		free(line_read);
	}
}
