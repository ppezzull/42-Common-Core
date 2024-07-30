/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:37:08 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/30 12:37:13 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	has_eaten_enough(t_philosopher *philo)
{
	return (philo->sim->eat_goal > 0 && philo->n_eat >= philo->sim->eat_goal);
}

void	kill_philos(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_len)
	{
		sim->philos[i].time_left = -1;
		i++;
	}
}

void	*supervisor(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	while (philo->time_left > get_current_time()
		&& has_eaten_enough(philo) == 0)
		usleep(10);
	if (has_eaten_enough(philo) == 1)
		philo->time_left = -1;
	else
	{
		pthread_mutex_lock(&philo->sim->lock);
		philo->sim->kill_switch = 1;
		kill_philos(philo->sim);
		philo->sim->death_time = get_current_time() - philo->sim->start_time;
		philo->sim->philo_dead = philo->id;
		pthread_mutex_unlock(&philo->sim->lock);
	}
	return (0);
}
