/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:16:15 by khelegbe          #+#    #+#             */
/*   Updated: 2022/03/17 15:32:17 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/* CONSTANTS */

# define BAD_ARGUMENT "Missing or too many arguments."
# define COM_ERROR "Processus communication error. (Maybe an invalid character)"

/* utils.c */

void	ft_putendl_fd(char *s, int fd);
void	print_error(char *str);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);

/* server.c */

#endif
