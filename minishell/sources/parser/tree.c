/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:59:16 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/26 15:55:05 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

t_tree	*tree_new_node(int type, t_tree *left, t_tree *right, char *value)
{
	t_tree	*node;

	node = ft_calloc(1, sizeof(t_tree));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = left;
	node->right = right;
	node->value = value;
	return (node);
}

void	tfree(t_tree **tree)
{
	free(tree);
}
