/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:23:53 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/10 16:52:47 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	is_next_ifd(t_tree *node)
{
	t_tree	*holder;

	if (!node)
		return (0);
	holder = node;
	while (node)
	{
		if (node->type == T_SL_REDIRECTION || node->type == T_DL_REDIRECTION)
			return (node = holder, 1);
		node = node->left;
	}
	node = holder;
	return (0);
}

int	get_cmd_ifd(t_tree *node)
{
	t_tree	*holder;
	t_tree	*last;
	int		ifd;

	holder = node;
	ifd = -1;
	if (node == T_WORD)
		node = node->left;
	while (node)
	{
		if (node->type == T_SL_REDIRECTION)
		{
			ifd = open(node->value, O_RDONLY);
			if (ifd == -1)
				ft_putendl_fd(ER_FILE_NFOUND, 1);
			if (ifd != -1 && is_next_ifd(node->left) == 1)
				close(ifd);
			else if (ifd == -1)
				return (-2);
			last = node;
		}
		else if (node->type == T_DL_REDIRECTION)
			last = node;
		node = node->left;
	}
	node = holder;
	if (last && last->type == T_DL_REDIRECTION)
		return (last->heredoc[0]);
	return (ifd);
}
