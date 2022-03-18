/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:51 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/18 15:18:40 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	g_global = 0;

void	waiting_sig(void)
{
	while (!g_global)
		usleep(1);
	if (g_global == 1)
		g_global = 0;
}

void	send_char(int pid, char c)
{
	char		i;
	int			to_send;

	i = 0;
	while (i < 8)
	{
		to_send = (c >> i++) & 1;
		if (kill(pid, SIGUSR1 + (to_send * 2)) == -1)
		{
			print_error("Error signal.");
			exit(1);
		}
		waiting_sig();
	}
}

void	cli_handler(int sig)
{
	if (sig == SIGUSR2)
		exit(1);
	g_global = 1;
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
	{
		print_error(BAD_ARGUMENT);
		return (1);
	}
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &cli_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		print_error(BAD_PID);
		return (1);
	}
	usleep(1000);
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
