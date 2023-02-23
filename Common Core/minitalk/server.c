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

int	power_of(int base, int exponent)
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

char	bin_to_char(char *bin)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (bin[i] == '1')
			c += power_of(2, 7 - i);
		i++;
	}
	return ((char)c);
}

void	signal_handler(int signum)
{
	static int	i = 0;
	static char	bin[8];

	if (signum == SIGUSR1)
		bin[i] = '1';
	if (signum == SIGUSR2)
		bin[i] = '0';
	i++;
	if (i == 8)
	{
		if (ft_strncmp(bin, "00000000", 8) == 0)
			ft_printf("\n");
		ft_printf("%c", bin_to_char(bin));
		i = -1;
		while (i++ < 8)
			bin[i] = '\0';
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
