/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:14:45 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/12 16:38:52 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	is_directory(char *path)
{
	struct stat	statbuf;

	if (lstat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

void	error_slash(t_program *program, char *cmd_name)
{
	if (is_directory(cmd_name))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(ER_CMD_DIRECTORY, 2);
		free_exit(program, 127);
	}
	else if (access(cmd_name, F_OK))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(ER_FILE_NFOUND, 2);
		free_exit(program, 127);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(ER_CMD_PERMS, 2);
		free_exit(program, 126);
	}
}

void	per_cmd_nfound(t_program *program, char *cmd_name)
{
	if (ft_strchr(cmd_name, '/') != 0)
		error_slash(program, cmd_name);
	else
	{
		ft_putstr_fd(cmd_name, 2);
		ft_putendl_fd(ER_CMD_NFOUND, 2);
		free_exit(program, 127);
	}
}

void	free_path_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
