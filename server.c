/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:28:27 by tnessrou          #+#    #+#             */
/*   Updated: 2021/09/04 21:42:42 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_bin	g_binary;

static void	receiving_handler(int s, siginfo_t *info, void *meta)
{
	meta = NULL;
	if (s == SIGUSR1)
		g_binary.data += 1 << (7 - g_binary.pow);
	g_binary.pow++;
	if (g_binary.pow == 8)
	{
		ft_putchar_fd(g_binary.data, 1);
		g_binary.data = 0;
		g_binary.pow = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			raise_error("Receiving error\n");
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	argv = NULL;
	if (argc != 1)
		raise_error("Check args\n");
	ft_putstr_fd("Server is working\nPID=", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	g_binary.data = 0;
	g_binary.pow = 0;
	action.sa_flags = SIGINFO;
	action.sa_sigaction = receiving_handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		raise_error("Receiving error\n");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		raise_error("Receiving error\n");
	while (322)
		pause();
	return (0);
}
