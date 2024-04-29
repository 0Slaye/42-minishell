/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/29 18:43:32 by tal-yafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

static int	ft_update_env(t_program *program, char **argv, int add)
{
	int	j;
	int	pos;
	int	sub;

	sub = 0;
	j = add;
	while (j > 0)
	{
		pos = ft_to_update(program, argv[j]);
		if (pos > 0)
		{
			program->envp[pos] = ft_strdup(argv[j]);
			if (!program->envp[pos])
				return (-1);
			sub++;
		}
		j--;
	}
	return (sub); 
}
static void	ft_add_to_env(char **argv, char **new_env, int j, int add)
{
	int	k;

	k = 1;
	while (add > 0)
	{
		if (argv[k] && ft_strchr(argv[k], '='))
		{
			new_env[j] = ft_strdup(argv[k]);
			if (!new_env[j])
			{
				ft_array_cleaner((void **)new_env, j);
				return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
			}
			j++;
			add--;
		}
		k++;
	}
	new_env[j] = NULL;
}

static void	ft_new_env(t_program *program, char **argv, int add)
{
	char	**new_env;
	int		env_size;
	int		j;
	int		create;

	if (ft_update_env(program, argv, add) < 0)
		return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
	create = add - ft_update_env(program, argv, add);
	env_size = ft_array_len(program->envp);
	new_env = ft_calloc(env_size + create + 1, sizeof(char *));
	if (!new_env)
		return ((void)ft_putendl_fd(ER_MALLOC_FUNC, 2));
	j = 0;
	while (j < env_size)
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
	ft_add_to_env(argv, new_env, j, create);
	program->envp = new_env;
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
			ft_new_env(program, argv, i);
	}
	return (free(argv));
}
