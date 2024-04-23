/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/23 15:33:50 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

int	is_allnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0' && ft_isdigit(arg[i]))
		i++;
	if (i != (int) ft_strlen(arg))
		return (0);
	return (1);
}

void	ft_exit(t_program *program, t_tree *node)
{
	char	**argv;
	int		holder;
	int		i;

	ft_putendl_fd("exit", 2);
	argv = get_cmd_option(node);
	if (!argv)
		return (ft_putendl_fd(ER_MALLOC_FUNC, 2), \
	free_exit(program, EXIT_FAILURE));
	i = 0;
	while (argv[i])
		i++;
	if (i > 2)
		return (free(argv), ft_putendl_fd(ER_EXIT_ARGS_NB, 2), \
	(void)(program->exit = EXIT_FAILURE));
	if (i == 1)
		return (free(argv), free_exit(program, 0));
	if (!is_allnum(argv[1]))
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd(argv[1], 2), \
	free(argv), ft_putendl_fd(ER_EXIT_ARG_VALUE, 2), free_exit(program, 2));
	holder = ft_atoi(argv[1]);
	free(argv);
	free_exit(program, holder % 256);
}
