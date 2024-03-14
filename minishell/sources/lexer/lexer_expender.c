/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expender.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:37:20 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/14 15:25:57 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	add_to_list(t_list **list, char *value, int type)
{
	t_token	*token;
	t_list	*holder;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (1);
	token->type = type;
	token->value = value;
	holder = ft_lstnew(token);
	if (!holder)
		return (free(token), 1);
	ft_lstadd_back(list, holder);
	return (0);
}

char	*get_expend_value(char *value, char **envp)
{
	int	i;
	int	length;

	length = 0;
	i = -1;
	while (value[++i] != ' ' && value[i] != D_QUOTE && value[i] != '\0')
		length++;
	if (length == 0 && value[0] != S_QUOTE && value[0] != D_QUOTE)
		return ("$");
	else if (value[0] == S_QUOTE || value[0] == D_QUOTE)
		return ("");
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], value, length) == 0)
			return (&envp[i][length + 1]);
	}
	return ("");
}

int	list_expend(t_list **list, char *value, char **envp)
{
	int		*hashmap;
	int		is_quotes;
	int		i;

	hashmap = ft_hashmap(value);
	if (!hashmap)
		return (1);
	is_quotes = 0;
	i = -1;
	while (value[++i] != '\0')
	{
		if (value[i] != '\0' && hashmap[i] == T_S_QUOTE && is_quotes == 0)
			is_quotes = 1;
		else if (value[i] != '\0' && hashmap[i] == T_S_QUOTE && is_quotes == 1)
			is_quotes = 0;
		if (value[i] == DOLLAR && is_quotes == 0)
		{
			if (add_to_list(list, get_expend_value(&value[i + 1], envp), 1) \
			!= 0)
				return (free(hashmap), 1);
			while (value[++i] != SPACE && value[i] != D_QUOTE \
			&& value[i] != S_QUOTE && value[i] != '\0')
				;
			i--;
		}
		else
		{
			if (add_to_list(list, &value[i], 0) != 0)
				return (free(hashmap), 1);
		}
	}
	if (add_to_list(list, "\0", 0) != 0)
		return (free(hashmap), 1);
	return (free(hashmap), 0);
}

char	*get_result_value(t_list **list)
{
	int		length;
	char	*result;
	int		i;
	int		j;

	length = get_list_value_length(list);
	result = ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (*list)
	{
		if (lexer_get_type(*list) == 1)
		{
			i = -1;
			while (lexer_get_value(*list)[++i] != '\0')
				result[j++] = lexer_get_value(*list)[i];
		}
		else
			result[j++] = lexer_get_value(*list)[0];
		*list = (*list)->next;
	}
	return (result);
}

char	*lexer_expender(char *value, char **envp)
{
	t_list	**lst;
	t_list	*holder;
	char	*result;

	lst = ft_calloc(1, sizeof(t_list *));
	if (!lst)
		return (NULL);
	if (ft_strchr(value, DOLLAR) == NULL)
		return (free(lst), ft_strdup(value));
	if (list_expend(lst, value, envp) != 0)
		return (ft_lstclear(lst, &free), free(lst), NULL);
	holder = *lst;
	result = get_result_value(lst);
	if (!result)
		return (ft_lstclear(lst, &free), free(lst), NULL);
	*lst = holder;
	return (ft_lstclear(lst, &free), free(lst), result);
}
