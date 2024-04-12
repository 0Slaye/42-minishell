/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/12 18:45:24 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	get_node_size(t_tree *node, int select)
{
	t_tree	*holder;
	int		result;

	holder = node;
	result = 0;
	if (!node || (select != 0 && select != 1))
		return (0);
	while (node)
	{
		if (select == 0)
			node = node->left;
		else
			node = node->right;
		result++;
	}
	node = holder;
	return (result);
}

char	**get_cmd_option(t_tree *node)
{
	t_tree	*holder;
	char	**result;
	int		size;
	int		i;

	i = -1;
	holder = node;
	size = get_node_size(node, 1);
	result = ft_calloc(size + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (++i < size)
	{
		result[i] = node->value;
		node = node->right;
	}
	result[i] = NULL;
	node = holder;
	return (result);
}

char	*get_envp_path(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
	}
	return (NULL);
}

void	path_execve(char *cmd, char **argv, t_program *program)
{
	char	*path;
	char	**paths;
	char	*holder;
	char	*builded_cmd;
	int		i;

	paths = NULL;
	if (ft_strchr(cmd, '/') != NULL)
		execve(cmd, argv, program->envp);
	else
	{
		path = get_envp_path(program->envp);
		if (!path)
			return (ft_putendl_fd(ER_CMD_NFOUND, 2)); // EXIT CODE HERE
		paths = ft_split(path, ':');
		if (!paths)
			return (ft_putendl_fd(ER_MALLOC_FUNC, 2)); // EXIT CODE HERE
		i = -1;
		while (paths[++i])
		{
			holder = ft_strjoin("/", cmd);
			builded_cmd = ft_strjoin(paths[i], holder);
			printf("%s\n", builded_cmd);
			check_perms(program, builded_cmd);
			execve(builded_cmd, argv, program->envp);
			free(holder);
			free(builded_cmd);
		}
	}
	return (free(argv), free_path_split(paths), per_cmd_nfound(program, cmd));
}
