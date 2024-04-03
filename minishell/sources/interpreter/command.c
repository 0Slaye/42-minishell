/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/03 16:21:41 by uwywijas         ###   ########.fr       */
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

void	path_execve(char *cmd, char **argv, char **envp)
{
	char	*path;
	char	**paths;
	char	*holder;
	char	*builded_cmd;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = &envp[i][5];
			break ;
		}
	}
	paths = ft_split(path, ':');
	if (!paths)
		return ;
	i = -1;
	while (paths[++i])
	{
		holder = ft_strjoin("/", cmd);
		builded_cmd = ft_strjoin(paths[i], holder);
		execve(builded_cmd, argv, envp);
		free(holder);
		free(builded_cmd);
	}
}

int	cmd_execute(t_tree *node, t_program *program)
{
	char	**options;
	int		id;

	if (ft_strncmp(node->value, "exit", 4) == 0)
		return (printf("exit\n"), 1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		options = get_cmd_option(node);
		execve(node->value, options, program->envp);
		path_execve(node->value, options, program->envp);
		free(options);
		ft_putstr_fd(node->value, 2);
		ft_putstr_fd(ER_CMD_NFOUND, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
