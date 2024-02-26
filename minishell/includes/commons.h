/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:23 by uwywijas          #+#    #+#             */
/*   Updated: 2024/02/26 14:37:21 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# define TRUE 1
# define FALSE 0
# define PROMPT "minishell: "

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// Prompt
int	prompt(void);

#endif