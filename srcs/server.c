/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:54 by khelegbe          #+#    #+#             */
/*   Updated: 2022/02/22 18:47:54 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void	print_str(int byte)
{
	static char	c = 0;
	static int	i = 0;
	static int	j = 0;
	static char	buffer[10000];

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
	}
}

void	handler(int n, )
{
	if (n == SIGUSR1)
		print_str(0);
	else if (n == SIGUSR2)
		print_str(1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

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
