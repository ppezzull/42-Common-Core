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

int power_of(int base, int exponent)
{
	int	n;
	
	n = base;
	if (exponent == 0)
		return (1);
	exponent--;
	while (exponent)
	{
		n *= base;
		exponent--;
	}
	return (n);
}

void	signal_handler(int signum)
{
	static int	c = 0;
	static int	i = 7;

	if (signum == SIGUSR1)
	{
		c += power_of(2, i);
	}
	i--;
	if (i == -1)
	{
		printf("%c\n", c);
		i = 7;
		c = 0;
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
