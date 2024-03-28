/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:54:29 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 18:13:19 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*ast(t_list **lexer)
{
	t_tree	*tree;

	tree = command_line(lexer);
	if (!tree)
		return (NULL);
	return (tree);
}
