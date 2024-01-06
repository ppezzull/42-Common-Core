/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insightful_dinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:24 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/30 12:37:26 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(t_philosopher *philo)
{
	t_philosopher	*philo_friend;

	philo_friend = get_philo_friend(philo);
	pthread_mutex_lock(&philo->fork);
	send_message(philo, FORK);
	pthread_mutex_lock(&philo_friend->fork);
	send_message(philo, FORK);
	philo->time_left = get_current_time() + (long long)philo->sim->time_die;
	send_message(philo, EAT);
	ft_usleep(philo->sim->time_eat);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo_friend->fork);
}

void	insightful_eating(t_philosopher *philo)
{
	if (philo->sim->philo_len == 1)
	{
		send_message(philo, FORK);
		ft_usleep(philo->sim->time_die);
	}
	else
	{
		eat(philo);
		send_message(philo, SLEEP);
		ft_usleep(philo->sim->time_sleep);
		send_message(philo, THINK);
	}
}

void	*insightful_dinner(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	philo->time_left = (long long)philo->sim->time_die + get_current_time();
	if (philo->id % 2 != 0)
		ft_usleep(philo->sim->time_eat - 10);
	pthread_create(&philo->supervisor, NULL, &supervisor, (void *)philo);
	pthread_detach(philo->supervisor);
	while (philo->time_left > get_current_time()
		&& philo->sim->kill_switch != 1)
		insightful_eating(philo);
	return (0);
}
