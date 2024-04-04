/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 12:49:27 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_list	*creates_list(t_tree *ast)
{
	t_list	*result;
	t_list	*new;
	t_tree	*holder;

	holder = ast;
	result = ft_lstnew(NULL);
	if (!result)
		return (NULL);
	while (ast)
	{
		new = ft_lstnew(NULL);
		if (!new)
			return (ft_lstclear(&result, &free), NULL);
		ft_lstadd_back(&result, new);
		ast = ast->right;
	}
	ast = holder;
	return (result);
}

t_list	*setup_pipes(t_tree *ast)
{
	t_list	*result;
	t_list	*holder;
	int		*pipefds;

	result = creates_list(ast);
	if (!result)
		return (NULL);
	holder = result;
	while (result)
	{
		pipefds = ft_calloc(2, sizeof(int));
		if (!pipefds)
			return (ft_lstclear(&holder, &free), NULL);
		if (pipe(pipefds) == -1)
			return (ft_lstclear(&holder, &free), NULL);
		result->content = pipefds;
		result = result->next;
	}
	result = holder;
	return (result);
}

void	close_pipes(t_list *pipe)
{
	while (pipe)
	{
		close(((int *) pipe->content)[0]);
		if (((int *) pipe->content)[1] != STDOUT_FILENO)
			close(((int *) pipe->content)[1]);
		pipe = pipe->next;
	}
}
