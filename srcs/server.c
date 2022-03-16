/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:54 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/16 16:23:46 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

// void	print_str(int byte, int pid)
// {
// 	static char	c = 0;
// 	static int	i = 0;
// 	static int	j = 0;
// 	static char	buffer[2048];

// 	(void)pid;
// 	c |= byte << i++;
// 	if (i == 8)
// 	{
// 		if (c == '\0')
// 		{
// 			buffer[j++] = '\n';
// 			buffer[j] = '\0';
// 			write(1, buffer, j);
// 			buffer[0] = '\0';
// 			j = 0;
// 		}
// 		else
// 			buffer[j++] = c;
// 		c = 0;
// 		i = 0;
// 	}
// 	printf("CLI PID : %d\n", pid);
// 	usleep(500);
	// kill(pid, SIGUSR1);
// }

static void	print_str(int byte_received, int pid)
{
	static int		bit = 0;
	static int		tmp = 0;

	tmp |= (byte_received << bit);
	if (tmp < 0 || tmp > 255)
	{
		tmp = 0;
		bit = 0;
		write(1, "\nError during communication\n", 29);
		usleep(500);
		kill(pid, SIGUSR2);
	}
	else if (++bit == 8)
	{
		if (tmp == '\0')
			write(1, "\n", 2);
		else
			write(1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
	// printf("CLI PID : %d\n", pid);
	usleep(500);
	kill(pid, SIGUSR1);
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
	struct sigaction	sa;

	(void)argv;
	if (argc > 1)
	{
		ft_putendl_fd("Error.", STDOUT_FILENO);
		ft_putendl_fd(BAD_ARGUMENT, STDOUT_FILENO);
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putendl_fd("SERVER PID:", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	while (1)
		pause();
	return (0);
}
