/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:28:24 by tnessrou          #+#    #+#             */
/*   Updated: 2021/09/05 17:43:57 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

static void	send_binary(char c, int pow, int pid)
{
	int	check;

	if (pow > 0)
		send_binary(c >> 1, pow - 1, pid);
	if ((c % 2) == 1)
		check = kill(pid, SIGUSR1);
	else
		check = kill(pid, SIGUSR2);
	if (check == -1)
		raise_error("Error in message sending\n");
	usleep(50);
}

static void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_binary(*message, 7, pid);
		message++;
	}
}

static void	response_handler(int s, siginfo_t *info, void *meta)
{
	s = 0;
	info = NULL;
	meta = NULL;
	ft_putstr_fd("Response received!!!\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
		raise_error("Check args\n");
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = response_handler;
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		raise_error("Response error\n");
	send_message(ft_atoi(argv[1]), argv[2]);
	while (228)
		pause();
	return (0);
}
