/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:54 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/18 15:57:19 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_str(int byte, int pid)
{
	static int		bit = 0;
	static int		tmp = 0;

	tmp |= (byte << bit);
	if (tmp < 0 || tmp > 255)
	{
		tmp = 0;
		bit = 0;
		print_error(COM_ERROR);
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
		print_error(BAD_ARGUMENT);
		return (1);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
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
