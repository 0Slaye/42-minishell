/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:12:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/03/12 17:25:53 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"

int	main(int argc, char **argv, char **envp)
{
	t_input	*input;

	input = malloc(sizeof(t_input));
	if (!input)
		return (1);
	input->argc = argc;
	input->argv = argv;
	input->envp = envp;
	prompt("minishell$ ", input);
	return (free(input), 0);
}
