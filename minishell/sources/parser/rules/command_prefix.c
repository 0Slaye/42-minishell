/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_prefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:31 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/28 16:53:46 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_tree	*command_prefix(t_list *lexer)
{
	t_tree	*prefix;

	prefix = redirect(lexer);
	if (prefix)
		prefix->left = command_prefix(lexer);
	return (prefix);
}
