/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:14:39 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/15 14:39:51 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	*redirect_setup(t_tree *node, t_tree **holder, int *fds)
{
	*holder = node;
	fds[0] = -1;
	fds[1] = -1;
	if (node == T_WORD)
		node = node->left;
	return (NULL);
}
