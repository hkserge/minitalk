/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:51 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/16 16:10:46 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	char		i;
	int			byte;

	i = 0;
	while (i < 8)
	{
		byte = (c >> i++) & 1;
		if (kill(pid, SIGUSR1 + (byte * 2)) == -1)
			print_error("Signal error.");
		pause();
	}
	// int	i;
	// int	to_send;

	// i = 0;
	// while (i < 8)
	// {
	// 	to_send = (c >> i++) & 1;
	// 	if (to_send == 0)
	// 	{
	// 		kill(pid, SIGUSR1);
	// 	}
	// 	else
	// 	{
	// 		kill(pid, SIGUSR2);
	// 	}
	// 	usleep(500);
	// }
}

void	cli_handler(int sig)
{
	if (sig == SIGUSR2)
		exit(1);
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	struct sigaction	sa;

	i = 0;
	if (argc != 3)
	{
		ft_putendl_fd("Error.", STDOUT_FILENO);
		ft_putendl_fd(BAD_ARGUMENT, STDOUT_FILENO);
		return (1);
	}
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &cli_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	usleep(1000);
	if (pid <= 0)
		return (1);
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
