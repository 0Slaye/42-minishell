/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:54:07 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 18:16:04 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*command_line(t_list **lexer)
{
	t_tree	*tree;

	tree = tree_new(G_PIPE, NULL, simple_command(*lexer), \
	piped_command(*lexer));
	if (!tree)
		return (free_tree(tree), NULL);
	return (tree);
}
