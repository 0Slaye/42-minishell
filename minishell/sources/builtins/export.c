/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/22 18:09:42 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

static int	ft_env_size(char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	return (size);
}

char	**ft_copy_env(t_program *program, t_tree *node)
{
	char	**new_env;
	int		env_size;
	int		j;
	int		size;

	size = 1; // temp
	env_size = ft_env_size(program->envp);
	new_env = ft_calloc(env_size + 1, sizeof(char *));
	if (!new_env)
		return (NULL);
	j = 0;
	while (j <= size)
	{
		new_env[j] = ft_strdup(program->envp[j]);
		j++;
	}
	new_env[j] = ft_strdup(node->value);
	new_env[j + 1] = 0;
	return (new_env);
}
void	ft_export(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;

	(void)program;
	argv = get_cmd_option(node);
	if (!argv)
		return ;
	i = 0;
	while (argv[i])
		i++;
	if (i == 1)
	{
		i = 0;
		while (program->envp[i])
		{
			printf("declare -x %s\n", program->envp[i]);
			i++;
		}
		return (free(argv));
	}
}
