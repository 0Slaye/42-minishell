/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:59:16 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/27 18:18:43 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

t_tree	*tree_new(int type, char *value, t_tree *left, t_tree *right)
{
	t_tree	*node;

	node = ft_calloc(1, sizeof(t_tree));
	if (!node)
		return (NULL);
	node->type = type;
	node->value = value;
	node->left = left;
	node->right = right;
	return (node);
}

void	show_tree(t_tree *tree, int n)
{
	int i;

	i = n;
	if (tree->right)
		show_tree(tree->right, n + 1);
	while (i-- > 0)
		printf("\t");
	if (tree)
		printf("[%d]: %s\n", tree->type, tree->value);
	if (tree->left)
		show_tree(tree->left, n + 1);
}

void	tfree(t_tree **tree)
{
	free(tree);
}
