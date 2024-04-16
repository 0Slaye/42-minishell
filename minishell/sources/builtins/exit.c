/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/16 15:42:24 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	ft_exit(t_program *program, t_tree *node)
{
	(void) program;
	(void) node;
	free_exit(program, EXIT_SUCCESS);
}
