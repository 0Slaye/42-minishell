/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/15 18:42:00 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	print_value(char **values, int start, int i)
{
	while (values[i])
	{
		if (i != start && values[i])
			printf(" ");
		printf("%s", values[i]);
		i++;
	}
}

void	ft_echo(t_tree *node)
{
	char	**argv;
	int		i;
	int		start;
	int		is_newline;

	is_newline = 1;
	argv = get_cmd_option(node);
	if (argv == NULL)
		return ((void) printf("\n"));
	i = 0;
	while (argv[++i] && ft_strncmp(argv[i], "-n", ft_strlen("-n")) == 0)
		is_newline = 0;
	if (i == 0)
		i++;
	start = i;
	print_value(argv, start, i);
	if (is_newline)
		printf("\n");
}
