/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:54:07 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/26 16:16:01 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	**command_line(t_list **lexer)
{
	t_tree	**tree;

	(void) lexer;
	tree = ft_calloc(1, sizeof(t_tree *));
	if (!tree)
		return (NULL);
	if (command(lexer, tree) != 0)
		return (tfree(tree), NULL);
	if (!ft_lstlast(*lexer))
		return (tfree(tree), printf(ER_PARSER_TOKEN, "newline"), NULL);
	return (tree);
}
