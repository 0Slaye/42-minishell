/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/05/02 15:00:02 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	print_smaller(char **envp)
{
	char	*holder;
	int		length;
	int		i;

	if (!envp)
		return ;
	holder = envp[0]; // need to delete
	i = 0;
	while (envp[i])
	{
		length = ft_max(ft_strlen(holder) - ft_strlen(ft_strchr(holder, '=')), ft_strlen(envp[i]) - ft_strlen(ft_strchr(envp[i], '=')));
		if (ft_strncmp(holder, envp[i], length) > 0)
			holder = envp[i];
		i++;
	}
	printf("%s\n", holder);
}

void	ft_export(t_program *program, t_tree *node)
{
	print_smaller(program->envp);
	(void) program;
	(void) node;
}
