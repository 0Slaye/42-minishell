/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:11:48 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/01 15:27:36 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

int	is_token(char *start, char *token)
{
	if (ft_strncmp(start, token, ft_strlen(token)) == 0)
		return (1);
	return (0);
}

int	get_word_lenght(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (is_token(&line[i], PIPE))
			break ;
		if (is_token(&line[i], DL_REDIRECTION))
			break ;
		if (is_token(&line[i], DR_REDIRECTION))
			break ;
		if (is_token(&line[i], SL_REDIRECTION))
			break ;
		if (is_token(&line[i], SR_REDIRECTION))
			break ;
	}
	return (i - 1);
}

void	show_lexer(t_list **lexing)
{
	while ((*lexing)->next != NULL)
	{
		printf("%d : ", (int)((t_token *)((*lexing)->content))->type);
		printf("[%s]\n", (char *)((t_token *)((*lexing)->content))->value);
		*lexing = (*lexing)->next;
	}
	printf("%d : ", (int)((t_token *)((*lexing)->content))->type);
	printf("[%s]\n", (char *)((t_token *)((*lexing)->content))->value);
}
