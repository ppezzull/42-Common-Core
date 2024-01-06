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

void	*supervisor(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	while (philo->time_left > get_current_time()
		&& has_eaten_enough(philo) == 0)
		;
	if (has_eaten_enough(philo) == 1)
		philo->time_left = -1;
	else
	{
		pthread_mutex_lock(&philo->sim->lock);
		send_message(philo, DEAD);
		philo->sim->kill_switch = 1;
		pthread_mutex_unlock(&philo->sim->lock);
	}
	return (0);
}
