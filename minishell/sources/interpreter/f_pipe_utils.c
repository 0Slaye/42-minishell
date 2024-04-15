/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pipe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:22:00 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/15 17:26:24 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	cmd_duping(t_program *program, int ifd, int ofd)
{
	if (dup2(ifd, STDIN_FILENO) == -1)
		return (sclose(ifd), sclose(ofd), free_exit(program, EXIT_FAILURE));
	sclose(ifd);
	if (dup2(ofd, STDOUT_FILENO) == -1)
		return (sclose(ofd), free_exit(program, EXIT_FAILURE));
	sclose(ofd);
}
