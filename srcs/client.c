/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:51 by khelegbe          #+#    #+#             */
/*   Updated: 2022/02/24 20:24:30 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, char c)
{
	int	i;
	int	to_send;

	i = 0;
	while (i < 8)
	{
		to_send = (c >> i++) & 1;
		if (to_send == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, '\0');
	return (0);
}
