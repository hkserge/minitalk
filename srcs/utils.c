/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:21:29 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/02 19:18:34 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	char	nline;

	nline = '\n';
	if (!fd || !s)
		return ;
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
	write(fd, &nline, 1);
}

int	print_error(char *str)
{
	ft_putendl_fd("Error.", STDOUT_FILENO);
	ft_putendl_fd(str, STDOUT_FILENO);
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		nbr = 2147483648;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	if (nbr < 10)
		ft_putchar_fd(nbr % 10 + '0', fd);
}

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
