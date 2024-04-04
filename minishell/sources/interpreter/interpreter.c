/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 12:02:14 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

t_list	*setup_pipes(t_tree *ast)
{
	t_list	*new;
	t_list	*result;
	void	*holder;
	int		*pipefds;

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
	holder = result;
	while (result)
	{
		pipefds = ft_calloc(2, sizeof(int));
		if (!pipefds)
			return (ft_lstclear(&result, &free), NULL);
		if (pipe(pipefds) == -1)
			return (ft_lstclear(&result, &free), NULL);
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

int	interpreter(t_tree *ast, t_program *program)
{
	t_list	*pipe;
	t_list	*holder;
	int		input_fd;
	int		result;
	int		hfd;

	(void) program;
	pipe = setup_pipes(ast);
	if (!pipe)
		return (1);
	holder = pipe;
	input_fd = STDIN_FILENO;
	while (ast && ast->left)
	{
		if (ast->right == NULL)
		{
			hfd = ((int *) pipe->content)[1];
			((int *) pipe->content)[1] = STDOUT_FILENO;
		}
		result = cmd_execute(ast->left, program, input_fd, pipe);
		if (ast->right == NULL)
			((int *) pipe->content)[1] = hfd;
		if (ast->right != NULL)
			close(((int *) pipe->content)[1]);
		if (result != 0)
			return (close_pipes(holder), ft_lstclear(&pipe, &free), result);
		input_fd = ((int *) pipe->content)[0];
		pipe = pipe->next;
		ast = ast->right;
	}
	wait(NULL);
	close_pipes(holder);
	return (ft_lstclear(&holder, &free), 0);
}
