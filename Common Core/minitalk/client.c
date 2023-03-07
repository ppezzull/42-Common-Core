/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:34:40 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/20 16:34:42 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(char *reason)
{
	ft_putstr(reason);
	exit(0);
}

void	send_endl(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(300);
		i++;
	}
}

void	send_message(char *message, int pid)
{
	int		i;
	int		bitshift;

	i = 0;
	while (message[i])
	{
		bitshift = 0;
		while (bitshift < 8)
		{
			if (message[i] & 0x80 >> bitshift)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("Wrong PID\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Wrong PID\n");
			}
			usleep(300);
			bitshift++;
		}
		i++;
	}
	send_endl(pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error("Wrong number of arguments ./client [pid] [message]\n");
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
