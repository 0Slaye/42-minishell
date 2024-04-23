/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:16:35 by uwywijas          #+#    #+#             */
/*   Updated: 2024/04/23 14:46:18 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons.h"
#include "errors.h"

void	sig_default(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = SIG_DFL;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

void	sig_ignore(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = SIG_IGN;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}

void	sigint_handler(int signal)
{
	printf("sig: %d\n", signal);
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	setup_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	bzero(&sigint, sizeof(sigquit));
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGINT, &sigint, NULL);
	bzero(&sigquit, sizeof(sigquit));
	sigquit.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sigquit, NULL);
}
