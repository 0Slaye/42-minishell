/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:51:57 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/09 16:53:38 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	convert;

	i = 0;
	convert = c;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == convert)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == convert)
		return ((char *) &s[i]);
	return (0);
}
