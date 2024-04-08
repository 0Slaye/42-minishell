/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:14:45 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/08 16:47:08 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	per_cmd_nfound(char *cmd_name)
{
	ft_putstr_fd(cmd_name, 2);
	ft_putendl_fd(ER_CMD_NFOUND, 2);
}

void	free_path_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
