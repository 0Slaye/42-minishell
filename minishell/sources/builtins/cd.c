/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaye <slaye@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/05/01 17:23:09 by slaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	update_pwds(t_program *program, char *current, char *next)
{
	char	*oldpwd;
	char	*pwd;

	if (!program->envp)
		return ;
	oldpwd = ft_strjoin("OLDPWD=", current);
	if (!oldpwd)
		return (perror("malloc"));
	pwd = ft_strjoin("PWD=", next);
	if (!pwd)
		return (perror("malloc"));
	if (is_env_containing(program, "PWD"))
		remove_to_envp(program, "PWD");
	if (is_env_containing(program, "OLDPWD"))
		remove_to_envp(program, "OLDPWD");
	add_to_envp(program, oldpwd);
	add_to_envp(program, pwd);
}

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
	char	current[1024];
	int		i;

	argv = get_cmd_option(node);
	if (!argv)
		return (ft_putendl_fd(ER_MALLOC_FUNC, 2), \
	program->exit = EXIT_FAILURE, (void) NULL);
	i = 0;
	getcwd(current, 1024);
	while (argv[i])
		i++;
	if (i > 2)
		return (ft_putendl_fd(ER_CD_ARGS_NB, 2), \
	program->exit = EXIT_FAILURE, (void) NULL);
	if (i == 1)
	{
		if (chdir(get_home(program->envp)) != 0)
			return (ft_putendl_fd(ER_HOME_NFOUND, 2), \
		perror(get_home(program->envp)), free_exit(program, EXIT_FAILURE));
		update_pwds(program, current, get_home(program->envp));
		return (program->exit = EXIT_SUCCESS, (void) NULL);
	}
	if (chdir(argv[1]) != 0)
		return (ft_putstr_fd("minishell: cd: ", 2), perror(argv[1]), \
	program->exit = EXIT_FAILURE, (void) NULL);
	update_pwds(program, current, argv[1]);
	program->exit = EXIT_SUCCESS;
}

void	ft_cd(t_program *program, t_tree *node)
{
	char	**argv;
	char	current[1024];
	int		i;

	argv = get_cmd_option(node);
	if (!argv)
		return (ft_putendl_fd(ER_MALLOC_FUNC, 2), \
	free_exit(program, EXIT_FAILURE));
	i = 0;
	getcwd(current, 1024);
	while (argv[i])
		i++;
	if (i > 2)
		return (ft_putendl_fd(ER_CD_ARGS_NB, 2), \
	free_exit(program, EXIT_FAILURE));
	if (i == 1)
	{
		if (chdir(get_home(program->envp)) != 0)
			return (ft_putendl_fd(ER_HOME_NFOUND, 2), \
		perror(get_home(program->envp)), free_exit(program, EXIT_FAILURE));
		update_pwds(program, current, get_home(program->envp));
		return (free_exit(program, EXIT_SUCCESS));
	}
	if (chdir(argv[1]) != 0)
		return (ft_putstr_fd("minishell: cd: ", 2), perror(argv[1]), \
	free_exit(program, EXIT_FAILURE));
	update_pwds(program, current, argv[1]);
	free_exit(program, EXIT_SUCCESS);
}
