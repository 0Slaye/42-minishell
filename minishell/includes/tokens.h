/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:52:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/05 13:08:59 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# define PIPE "|"
# define SL_REDIRECTION "<"
# define SR_REDIRECTION ">"
# define DL_REDIRECTION "<<"
# define DR_REDIRECTION ">>"

enum e_tokens
{
	T_WORD,
	T_PIPE,
	T_SL_REDIRECTION,
	T_SR_REDIRECTION,
	T_DL_REDIRECTION,
	T_DR_REDIRECTION
};

typedef struct s_token
{
	int		type;
	void	*value;
}	t_token;

#endif