/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:54:07 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/27 18:07:18 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	**command_line(t_list **lexer)
{
	t_tree	**tree;

	tree = ft_calloc(1, sizeof(t_tree *));
	if (!tree)
		return (NULL);
	*tree = tree_new(G_PIPE, "|", simple_command(*lexer), NULL);
	if (!(*tree))
		return (tfree(tree), NULL);
	show_tree(*tree, 0);
	return (tfree(tree), NULL);
}
