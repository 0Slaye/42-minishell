/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:45:37 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/23 14:32:29 by tal-yafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

// static void	ft_print_env(char *env)
// {
// 	int	i;
	
// 	i = 0;
// 	printf("declare -x ");
// 	while (env[i] != '=')
// 	{
// 		printf("%c", env[i]);
// 		i++;
// 	}
// 	printf("=\"");
// 	i++;
// 	while (env[i])
// 	{
// 		printf("%c", env[i]);
// 		i++;
// 	}
// 	printf("\"\n");
// }
static int	ft_array_len(char **array)
{
	int	size;

	size = 0;
	while (array[size])
		size++;
	return (size);
}

static void	ft_add_to_env(char **argv, char **new_env, int j, int add)
{
	int	k;

	while (add > 0)
	{
		k = 1;
		new_env[j] = ft_strdup(argv[k]);
		j++;
		k++;
		add--;
	}
	new_env[j] = NULL;
}

static void	ft_copy_env(t_program *program, char **argv, int add)
{
	char	**new_env;
	int		env_size;
	int		j;

	env_size = ft_array_len(program->envp);
	new_env = ft_calloc(env_size + add + 1, sizeof(char *));
	if (!new_env)
		exit(EXIT_FAILURE);
	env_size = ft_array_len(new_env);
	j = 0;
	while (j < env_size - add)
	{
		new_env[j] = ft_strdup(program->envp[j]);
		free(program->envp[j]);
		j++;
	}
	ft_add_to_env(argv, new_env, j, add);
	program->envp = new_env;
	j = env_size;
	while (j > 0)
	{
		free(new_env[j]);
		j--;
	}
	free(new_env);
}
void	ft_export(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;

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
			ft_print_env(program->envp[i]);
			i++;
		}
	}
	else if ( i > 1)
		ft_copy_env(program, argv, i);
	return (free(argv));	
}
