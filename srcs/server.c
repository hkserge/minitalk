/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:54 by khelegbe          #+#    #+#             */
/*   Updated: 2022/02/24 20:24:26 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_str(int byte, int pid)
{
	static char	c = 0;
	static int	i = 0;
	static int	j = 0;
	static char	buffer[2048];

	(void)pid;
	c |= byte << i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			buffer[j++] = '\n';
			buffer[j] = '\0';
			write(1, buffer, j);
			buffer[0] = '\0';
			j = 0;
		}
		else
			buffer[j++] = c;
		c = 0;
		i = 0;
		// kill(pid, SIGUSR1);
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		print_str(0, info->si_pid);
	else if (sig == SIGUSR2)
		print_str(1, info->si_pid);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
		return (1);
	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	printf("SERVER PID = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
