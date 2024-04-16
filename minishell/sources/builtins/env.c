/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:14:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/16 15:44:58 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	ft_env(t_program *program)
{
	int	i;

	i = 0;
	while (program->envp[i])
	{
		printf("%s\n", program->envp[i]);
		i++;
	}
}
