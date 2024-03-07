/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/07 11:27:58 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	add_token(t_list **list, int type, char *value)
{
	t_list	*holder;
	t_token	*token;

	token = get_token(type, value);
	if (!token)
		return (-1);
	holder = ft_lstnew(token);
	if (!holder)
		return (free(token), -1);
	ft_lstadd_back(list, holder);
	if (type != T_WORD)
		return (0);
	if (!value)
		return (0);
	return (ft_strlen(value) - 1);
}

int	tokenize(int *hashmap, char *line, t_list **list)
{
	int	offset;

	if (hashmap[0] == T_PIPE)
		offset = add_token(list, T_PIPE, NULL);
	else if (hashmap[0] == T_SL_REDIRECTION)
		offset = add_token(list, T_SL_REDIRECTION, NULL);
	else if (hashmap[0] == T_SR_REDIRECTION)
		offset = add_token(list, T_SR_REDIRECTION, NULL);
	else
		offset = add_token(list, T_WORD, get_word(hashmap, line));
	return (offset);
}

t_list	**hashmap_parse(int *hashmap, char *line)
{
	t_list	**result;
	int		i;

	result = ft_calloc(1, sizeof(t_list *));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < (int) ft_strlen(line))
		i += tokenize(&hashmap[i], &line[i], result);
	return (result);
}

t_list	**lexer(char *line, t_input *input)
{
	t_list	**lexer;
	int		*hashmap;

	(void) input;
	hashmap = ft_hashmap(line);
	if (!hashmap)
		return (NULL);
	lexer = hashmap_parse(hashmap, line);
	show_lexer(lexer);
	free_lexer(lexer);
	return (free(hashmap), NULL);
}
