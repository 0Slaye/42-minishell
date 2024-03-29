/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:54:29 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/29 16:30:29 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	return_error(t_list *token)
{
	// if (!token)
	// 	return ;
	ft_putstr_fd(ER_PARSER_TOKEN, 2);
	ft_putstr_fd("`", 2);
	if (lexer_get_type(token) == T_WORD)
		ft_putstr_fd(lexer_get_value(token), 2);
	else if (lexer_get_type(token) == T_PIPE)
		ft_putstr_fd("|", 2);
	else if (lexer_get_type(token) == T_SL_REDIRECTION)
		ft_putstr_fd("<", 2);
	else if (lexer_get_type(token) == T_SR_REDIRECTION)
		ft_putstr_fd(">", 2);
	else if (lexer_get_type(token) == T_DL_REDIRECTION)
		ft_putstr_fd("<<", 2);
	else if (lexer_get_type(token) == T_DR_REDIRECTION)
		ft_putstr_fd(">>", 2);
	ft_putstr_fd("'\n", 2);
}

t_tree	*ast(t_list **lexer)
{
	t_tree	*tree;

	tree = command_line(lexer);
	if (!tree)
		return (NULL);
	return (tree);
}
