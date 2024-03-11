/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_formater_expender.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:37:20 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/11 17:13:08 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	get_var_length(char **envp, char *var, int select)
{
	int	i;
	int	length;

	length = 0;
	i = -1;
	while (var[++i] != ' ' && var[i] != D_QUOTE && var[i] != '\0')
		length++;
	if (length == 0)
		return (1);
	if (select == 0)
		return (length);
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], var, length) == 0)
			return (ft_strlen(envp[i]) - length - 1);
	}
	return (-1);
}

int	get_expended_length(char **envp, char *value, int *hashmap)
{
	int	result;
	int	i;

	result = 0;
	i = -1;
	while (value[++i] != '\0')
	{
		if (hashmap[i] == T_S_QUOTE)
		{
			while (hashmap[++i] != T_S_QUOTE)
				result++;
			i++;
			result++;
		}
		if (value[i] == DOLLAR)
		{
			if (get_var_length(envp, &value[i + 1], 1) == -1)
				return (-1);
			result += get_var_length(envp, &value[i + 1], 1);
			i += get_var_length(envp, &value[i + 1], 0);
		}
		else
			result++;
		if (value[i] == '\0')
			break ;
	}
	return (result);
}

int	expend_case(t_list **lexer, char **envp)
{
	char	*value;
	char	*result;
	int		*hashmap;

	value = lexer_get_value(*lexer);
	if (ft_strchr(value, DOLLAR) == NULL)
		return (0);
	hashmap = ft_hashmap(value);
	if (!hashmap)
		return (1);
	printf("%d\n", get_expended_length(envp, value, hashmap));
	if (get_expended_length(envp, value, hashmap) == -1)
		return (free(hashmap), 1);
	result = ft_calloc(get_expended_length(envp, value, hashmap) + 1, sizeof(char));
	if (!result)
		return (free(hashmap), 1);
	return (free(hashmap), 0);
}
