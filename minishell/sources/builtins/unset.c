/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/30 18:10:53 by tal-yafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"
// Finds the right string but doesn't skip it
// Delete it | don't add it to the new_e
static void	ft_smaller_env(t_program *program, int pos)
{
	char	**new_e;
	int		j;
	
	printf("%d\n", ft_array_len(program->envp));
	new_e = ft_calloc(ft_array_len(program->envp), sizeof(char *));
	if (!new_e)
		return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
	j = 0;
	while (j < ft_array_len(program->envp) && j != pos)
	{
		new_e[j] = ft_strdup(program->envp[j]);
		if (!new_e[j])
		{
			ft_array_cleaner((void **)new_e, j);
			return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
		}
		j++;
	}
	if (j == pos)
		printf("%d | %s\n", j, program->envp[j]);
	{
		while (j < ft_array_len(program->envp) && program->envp[j + 1])
		{
			new_e[j] = ft_strdup(program->envp[j + 1]);
			if (!new_e[j])
			{
				ft_array_cleaner((void **)new_e, j);
				return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
			}
			j++;
		}
	}
	while (j < ft_array_len(program->envp))
	{
		new_e[j] = NULL;
		j++;
	}
	ft_array_cleaner((void **)program->envp, j);
	program->envp = new_e;
}

void	ft_unset(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;
	int		pos;
	int		size;

	argv = get_cmd_option(node);
	if (!argv)
		return ;
	i = 1;
	while (argv[i])
	{
		size = ft_strlen(argv[i]);
		pos = 0;
		while (program->envp[pos])
		{
			if (ft_strncmp(argv[i], program->envp[pos], size) == 0)
				ft_smaller_env(program, pos);
			pos++;
		}
		i++;
	}
	return (free(argv));
}
