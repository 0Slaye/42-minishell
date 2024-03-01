/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/01 15:27:49 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

t_token	*get_token(int type, char *value)
{
	t_token	*token;

	if (!value)
		return (NULL);
	token = malloc(sizeof(t_token *));
	if (!token && type == T_WORD)
		return (free(value), NULL);
	else if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	return (token);
}

int	add_token(t_list **list, t_token *token)
{
	t_list	*holder;

	holder = ft_lstnew(token);
	if (!token || !holder)
		return (1);
	ft_lstadd_back(list, holder);
	return (0);
}

char	*get_value(char *line, int type)
{
	char	*result;
	int		i;

	i = -1;
	if (type != T_WORD)
		return ("token\0");
	result = malloc(sizeof(char) * (get_word_lenght(line) + 1));
	if (!result)
		return (NULL);
	result[get_word_lenght(line)] = '\0';
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
		result[i] = line[i];
	}
	return (result);
}

t_list	**lexer(char *line)
{
	t_list	**lexing;
	t_token	*token;
	int		type;
	int		i;

	lexing = malloc(sizeof(t_list **));
	if (!lexing)
		return (NULL);
	*lexing = NULL;
	i = -1;
	type = -1;
	while (line[++i] != '\0')
	{
		if (is_token(&line[i], PIPE))
			type = T_PIPE;
		else if (is_token(&line[i], DL_REDIRECTION))
			type = T_DL_REDIRECTION;
		else if (is_token(&line[i], DR_REDIRECTION))
			type = T_DR_REDIRECTION;
		else if (is_token(&line[i], SL_REDIRECTION))
			type = T_SL_REDIRECTION;
		else if (is_token(&line[i], SR_REDIRECTION))
			type = T_SR_REDIRECTION;
		else
			type = T_WORD;
		if (type == T_DL_REDIRECTION || type == T_DR_REDIRECTION)
			i++;
		token = get_token(type, get_value(&line[i], type));
		add_token(lexing, token);
		if (type == T_WORD)
			i += get_word_lenght(&line[i]);
	}
	show_lexer(lexing);
	return (lexing);
}
