/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/10 17:47:18 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	sclose(int fd)
{
	if (fd == -1)
		return ;
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO)
	{
		close(fd);
		fd = -1;
	}
}
