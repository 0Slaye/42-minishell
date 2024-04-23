/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:35:59 by tal-yafi          #+#    #+#             */
/*   Updated: 2024/04/23 17:32:07 by tal-yafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	ft_array_len(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

void	ft_print_env(char *env)
{
	int	i;
	
	i = 0;
	printf("declare -x ");
	while (env[i] != '=')
	{
		printf("%c", env[i]);
		i++;
	}
	printf("=\"");
	i++;
	while (env[i])
	{
		printf("%c", env[i]);
		i++;
	}
	printf("\"\n");
}