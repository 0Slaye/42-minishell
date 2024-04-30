/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/30 14:06:21 by tal-yafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

static int	ft_update_env(t_program *program, char *argv)
{
	int	pos;

	pos = ft_to_update(program, argv);
	if (pos >= 0)
	{
		free (program->envp[pos]);
		program->envp[pos] = ft_strdup(argv);
		if (!program->envp[pos])
			return (1);
		return (-1);
	}
	return (0);
}

static void	ft_add_to_env(char *argv, char **new_env, int j)
{
	if (argv && ft_strchr(argv, '='))
	{
		new_env[j] = ft_strdup(argv);
		if (!new_env[j])
		{
			ft_array_cleaner((void **)new_env, j);
			return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
		}
	}
	new_env[j + 1] = NULL;
}

static void	ft_new_env(t_program *program, char **argv)
{
	char	**new_env;
	int		j;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_update_env(program, argv[i]) > 0)
			return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
		if (ft_update_env(program, argv[i]) == 0)
		{
			new_env = ft_calloc(ft_array_len(program->envp) + 2, sizeof(char *));
			if (!new_env)
				return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
			j = 0;
			while (j < ft_array_len(program->envp))
			{
				new_env[j] = ft_strdup(program->envp[j]);
				if (!new_env[j])
				{
					ft_array_cleaner((void **)new_env, j);
					return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
				}
				j++;
			}
			ft_array_cleaner((void **)program->envp, j);
			ft_add_to_env(argv[i], new_env, j);
			program->envp = new_env;
		}
		i++;
	}
}

void	ft_export(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;

	argv = get_cmd_option(node);
	if (!argv)
		return ;
	i = 1;
	while (argv[i])
	{
		if (ft_valid_arg(argv[i]) > 0)
			return (free(argv), (void)ft_putendl_fd(ER_EXPORT_ID, 2));
		i++;
	}
	if (i == 1)
		ft_print_env(program->envp);
	else if (i > 1)
	{
		i = ft_env_args(argv);
		if (i != 0)
			ft_new_env(program, argv);
	}
	return (free(argv));
}
