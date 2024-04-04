/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 12:28:06 by uwywijas         ###   ########.fr       */
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

void	path_execve(char *cmd, char **argv, char **envp)
{
	char	*path;
	char	**paths;
	char	*holder;
	char	*builded_cmd;
	int		i;

	path = get_envp_path(envp);
	if (!path)
		return ;
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

int	cmd_execute(t_tree *node, t_program *program, int input_fd, t_list *pipe)
{
	char	**options;
	int		id;

	(void) pipe;
	if (!node)
		return (-1);
	if (ft_strncmp(node->value, "exit", 4) == 0)
		return (printf("exit\n"), -2);
	id = fork();
	if (id == -1)
		return (-1);
	if (id == 0)
	{
		dup2(input_fd, STDIN_FILENO);
		if (input_fd != STDIN_FILENO)
			close(input_fd);
		close(((int *) pipe->content)[0]);
		
		dup2(((int *) pipe->content)[1], STDOUT_FILENO);
		if (((int *) pipe->content)[1] != STDOUT_FILENO)
			close(((int *) pipe->content)[1]);

		options = get_cmd_option(node);
		execve(node->value, options, program->envp);
		path_execve(node->value, options, program->envp);
		free(options);
		ft_putstr_fd(node->value, 2);
		ft_putstr_fd(ER_CMD_NFOUND, 2);
		exit(EXIT_FAILURE);
	}
	return (id);
}
