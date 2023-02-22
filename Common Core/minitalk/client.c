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

# include "minitalk.h"

void	send_message(char *message, int pid)
{
	int		bitshift;
	int		i;

	i = 0;
	while (message[i])
    {
		bitshift = -1;
    	while (++bitshift < 8)
    	{
   			if (message[i] & 0x80 >> bitshift)
				kill(pid,SIGUSR1);
   			else
				kill(pid,SIGUSR2);
			usleep(3);
    	}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
        ft_printf("This program needs 2 argouments instead of %i\n", argc - 1);
        exit(EXIT_FAILURE);
	}
    pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(message, pid);
    return(0);
}
