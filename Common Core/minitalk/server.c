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

# include "minitalk.h"

void	signal_handler1(int signum)
{
	(void)signum;
	ft_printf("1");
}

void	signal_handler2(int signum)
{
	(void)signum;
	ft_printf("0");
}

int main()
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID = [%i]\n", pid);
	signal(SIGUSR1, signal_handler1);
	signal(SIGUSR2, signal_handler2);
	while (1)
		pause();
}