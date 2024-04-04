/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:02:21 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/04 16:44:11 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	last_command_fd(t_tree *ast, t_list *pipe, int *hfd)
{
	if (ast->right == NULL)
	{
		*hfd = ((int *) pipe->content)[1];
		((int *) pipe->content)[1] = STDOUT_FILENO;
	}
}

void	holder_fd_handle(t_tree *ast, t_list *pipe, int hfd)
{
	if (ast->right == NULL)
		((int *) pipe->content)[1] = hfd;
	if (ast->right != NULL)
		close(((int *) pipe->content)[1]);
}

void	loop_update(t_tree **ast, t_list **pipe, int *input_fd)
{
	*input_fd = ((int *)(*pipe)->content)[0];
	*pipe = (*pipe)->next;
	*ast = (*ast)->right;
}

int	interpreter(t_tree *ast, t_program *program)
{
	t_list	*pipe;
	t_list	*holder;
	int		input_fd;
	int		result;
	int		i;

	input_fd = STDIN_FILENO;
	pipe = setup_pipes(ast);
	if (!pipe)
		return (1);
	i = 0;
	holder = pipe;
	while (ast && ast->left)
	{
		if (ast->right == NULL)
		{
			close(((int *) pipe->content)[1]);
			((int *) pipe->content)[1] = STDOUT_FILENO;
		}
		result = cmd_execute(ast->left, program, input_fd, pipe);
		close(((int *) pipe->content)[0]);
		if (((int *) pipe->content)[1] != STDOUT_FILENO)
			close(((int *) pipe->content)[1]);
		if (result < 0)
			return (close_pipes(holder), ft_lstclear(&pipe, &free), -result);
		loop_update(&ast, &pipe, &input_fd);
		i++;
	}
	waitpid(result, NULL, 0);
	wait(NULL);
	return (ft_lstclear(&holder, &free), 0);
}
