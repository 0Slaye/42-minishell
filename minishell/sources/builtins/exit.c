/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/18 15:42:41 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	ft_exit(t_program *program, t_tree *node)
{
	char	**argv;
	int		holder;
	int		i;

	printf("exit\n");
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
	if (ft_strlen(argv[1]) > ft_strlen("9223372036854775807"))
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd(argv[1], 2), \
	free(argv), ft_putendl_fd(ER_EXIT_ARG_VALUE, 2), free_exit(program, 2));
	holder = ft_atoi(argv[1]);
	free(argv);
	free_exit(program, holder % 256);
}
