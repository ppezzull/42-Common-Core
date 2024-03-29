/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:46 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/30 12:37:50 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	m;
	int	i;
	int	num;

	i = 0;
	m = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		m = -m;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (m * num);
}

void	send_message(t_philosopher *philo, char *message)
{
	long long	time;

	time = get_current_time() - philo->sim->start_time;
	if (philo->sim->kill_switch == 0)
		printf("%lld %i %s\n", time, philo->id + 1, message);
}

long long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(int milliseconds)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < (long long)milliseconds)
		usleep(1);
}

t_philosopher	*get_philo_friend(t_philosopher *philo)
{
	if (philo->id == philo->sim->philo_len - 1)
		return (&philo->sim->philos[0]);
	else
		return (&philo->sim->philos[philo->id + 1]);
}
