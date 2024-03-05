/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/05 11:34:13 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "tokens.h"

int	get_type(char *line)
{
	if (is_token(line, PIPE))
		return (T_PIPE);
	if (is_token(line, DL_REDIRECTION))
		return (T_DL_REDIRECTION);
	if (is_token(line, DR_REDIRECTION))
		return (T_DR_REDIRECTION);
	if (is_token(line, SL_REDIRECTION))
		return (T_SL_REDIRECTION);
	if (is_token(line, SR_REDIRECTION))
		return (T_SR_REDIRECTION);
	else
		return (T_WORD);
}

void	get_value(char *line, char *value, int type)
{
	int		i;

	i = -1;
	if (type != T_WORD)
		return ;
	value[get_word_lenght(line, type)] = '\0';
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
		value[i] = line[i];
	}
}

t_token	*get_token(char *line, int type)
{
	t_token	*token;
	char	*value;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	value = ft_calloc(get_word_lenght(line, type) + 1, sizeof(char));
	if (!value)
		return (free(token), NULL);
	get_value(line, value, type);
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

t_list	**lexer(char *line)
{
	t_list	**lexing;
	t_token	*token;
	int		type;
	int		i;

	lexing = ft_calloc(1, sizeof(t_list **));
	if (!lexing)
		return (NULL);
	*lexing = NULL;
	i = -1;
	type = -1;
	while (i <= (int) ft_strlen(line) && line[++i] != '\0')
	{
		type = get_type(&line[i]);
		if (type == T_DL_REDIRECTION || type == T_DR_REDIRECTION)
			i++;
		token = get_token(&line[i], type);
		if (!token)
			return (free_lexing(lexing), NULL);
		add_token(lexing, token);
		if (type == T_WORD)
			i += get_word_lenght(&line[i], type) - 1;
	}
	return (show_lexing(lexing), free_lexing(lexing), NULL);
}
