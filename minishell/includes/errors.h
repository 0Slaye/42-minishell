/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:34:17 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/03 15:20:03 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

// Lexer
# define ER_LEXER_QUOTE "minishell: error when parsing for quotes\n"

// Parser
# define ER_PARSER_TOKEN "minishell: syntax error near unexpected token "

// Interpreter
# define ER_CMD_NFOUND ": command not found\n"

#endif