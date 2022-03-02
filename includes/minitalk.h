/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:16:15 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/02 20:22:42 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

/* CONSTANTS */

# define BAD_ARGUMENT "Missing or too many arguments."

/* utils.c */

void	ft_putendl_fd(char *s, int fd);
int		print_error(char *str);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(char *str);

/* server.c */

void	handler(int sig, siginfo_t *info, void *context);

#endif
