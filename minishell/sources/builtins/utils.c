/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tal-yafi <tal-yafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:35:59 by tal-yafi          #+#    #+#             */
/*   Updated: 2024/04/30 10:39:37 by tal-yafi         ###   ########.fr       */
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

void	ft_array_cleaner(void **array, int position)
{
	while (position != 0)
	{
		free(array[position]);
		position--;
	}
	free(array[position]);
	free (array);
}

static void	ft_iter_print(char *env)
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

// static int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i] && s1[i] != '=' && s2[i] != '=')
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

// Add alphabetical order sorting !
// Alphabetical NOT WORKING
void	ft_print_env(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		ft_iter_print(envp[i]);
		i++;
	}
}

char	**ft_dup_envp(char **envp)
{
	char	**dup_env;
	int		env_size;
	int		j;

	if (!envp)
		return (NULL);
	env_size = ft_array_len(envp);
	dup_env = ft_calloc(env_size + 1, sizeof(char *));
	if (!dup_env)
		return (NULL);
	j = 0;
	while (j < env_size)
	{
		dup_env[j] = ft_strdup(envp[j]);
		if (!dup_env[j])
		{
			ft_array_cleaner((void **)dup_env, j);
			return (ft_putendl_fd(ER_MALLOC_FUNC, 2), NULL);
		}
		j++;
	}
	dup_env[j] = NULL;
	return (dup_env);
}
