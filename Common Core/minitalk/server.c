/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:34:21 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/20 16:34:23 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	bin_to_char(char *bin)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	while (i++ < 8)
		if (bin[i] == '1')
			c += ft_pow(2, 7 - i);
	return ((char)c);
}

void	signal_handler(int signum)
{
	static int	i = 0;
	static char	bin[8];
	// char		letter;

	if (signum == SIGUSR1)
		bin[i] = '1';
	if (signum == SIGUSR2)
		bin[i] = '0';
	i++;
	if (i == 8)
	{
		// if ((letter = bin_to_char(bin)) == 0)
		// {
		// 	ft_putchar('\n');
		// 	ft_bzero(bin, 8);
		// }
		printf("%s -> %c\n",bin, bin_to_char(bin));
		// ft_putchar(letter);
		ft_bzero(bin, 8);
		i = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID = [%i]\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
