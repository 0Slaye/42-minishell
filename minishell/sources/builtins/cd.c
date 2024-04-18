/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/18 16:00:21 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

char	*get_home(char **envp)
{
	int	i;

	i = -1;
	if (!envp)
		return (NULL);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "HOME=", 5) == 0)
			return (&(envp[i][5]));
	}
	return (NULL);
}

void	ft_solo_cd(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;

	argv = get_cmd_option(node);
	if (!argv)
		return (ft_putendl_fd(ER_MALLOC_FUNC, 2), \
	program->exit = EXIT_FAILURE, (void) NULL);
	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
		return (ft_putendl_fd(ER_CD_ARGS_NB, 2), \
	program->exit = EXIT_FAILURE, (void) NULL);
	if (i == 1)
	{
		if (chdir(get_home(program->envp)) != 0)
			return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd("cd: ", 2), \
		perror(get_home(program->envp)), free_exit(program, EXIT_FAILURE));
		return (program->exit = EXIT_SUCCESS, (void) NULL);
	}
	if (chdir(argv[1]) != 0)
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd("cd: ", 2), \
	perror(argv[1]), program->exit = EXIT_FAILURE, (void) NULL);
	program->exit = EXIT_SUCCESS;
}

void	ft_cd(t_program *program, t_tree *node)
{
	char	**argv;
	int		i;

	argv = get_cmd_option(node);
	if (!argv)
		return (ft_putendl_fd(ER_MALLOC_FUNC, 2), \
	free_exit(program, EXIT_FAILURE));
	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
		return (ft_putendl_fd(ER_CD_ARGS_NB, 2), \
	free_exit(program, EXIT_FAILURE));
	if (i == 1)
	{
		if (chdir(get_home(program->envp)) != 0)
			return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd("cd: ", 2), \
		perror(get_home(program->envp)), free_exit(program, EXIT_FAILURE));
	}
	if (chdir(argv[1]) != 0)
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd("cd: ", 2), \
	perror(argv[1]), free_exit(program, EXIT_FAILURE));
}
