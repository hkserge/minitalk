/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:20:51 by khelegbe          #+#    #+#             */
/*   Updated: 2022/02/16 14:55:28 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	kill((int)argv[1], (int)argv[2]);
	return (0);
}
