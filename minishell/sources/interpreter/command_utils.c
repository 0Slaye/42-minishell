/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:14:45 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 13:19:08 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	per_cmd_nfound(char *cmd_name)
{
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd(ER_CMD_NFOUND, 2);
}
