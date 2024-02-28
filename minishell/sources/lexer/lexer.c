/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:12:02 by uwywijas          #+#    #+#             */
/*   Updated: 2024/02/28 18:22:17 by uwywijas         ###   ########.fr       */
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

t_list	**lexer(char *line)
{
	t_list	**result;
	int		i;

	result = malloc(sizeof(t_list **));
	if (!result)
		return (NULL);
	i = -1;
	while (line[++i] != '\0')
	{
		if (is_token(&line[i], PIPE))
			printf("PIPE ");
		else if (is_token(&line[i], DL_REDIRECTION))
		{
			printf("DL_REDIRECTION ");
			i++;
		}
		else if (is_token(&line[i], DR_REDIRECTION))
		{
			printf("DR_REDIRECTION ");
			i++;
		}
		else if (is_token(&line[i], SL_REDIRECTION))
			printf("SL_REDIRECTION ");
		else if (is_token(&line[i], SR_REDIRECTION))
			printf("SR_REDIRECTION ");
		else
		{
			printf("[");
			while (line[i] != '\0')
			{
				if (is_token(&line[i], PIPE))
				{
					i--;
					break;
				}
				if (is_token(&line[i], DL_REDIRECTION))
				{
					i--;
					break;
				}
				if (is_token(&line[i], DR_REDIRECTION))
				{
					i--;
					break;
				}
				if (is_token(&line[i], SL_REDIRECTION))
				{
					i--;
					break;
				}
				if (is_token(&line[i], SR_REDIRECTION))
				{
					i--;
					break;
				}
				printf("%c", line[i]);
				i++;
			}
			printf("] ");
		}
	}
	free(result);
	printf("\n");
	return (NULL);
}
