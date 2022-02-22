/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:51 by khelegbe          #+#    #+#             */
/*   Updated: 2022/02/22 16:07:41 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - '0';
		}
		i++;
	}
	return (result * sign);
}

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
		usleep(50);
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
