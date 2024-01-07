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

#include "../includes/philo_bonus.h"

void	eat(t_philosopher *philo)
{
	sem_wait(philo->sim->semaphore);
	send_message(philo, FORK);
	sem_wait(philo->sim->semaphore);
	send_message(philo, FORK);
	philo->time_left = get_current_time() + (long long)philo->sim->time_die;
	send_message(philo, EAT);
	ft_usleep(philo->sim->time_eat);
	philo->n_eat++;
	sem_post(philo->sim->semaphore);
	sem_post(philo->sim->semaphore);
}

void	*supervisor(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	philo->time_left = get_current_time() + (long long)philo->sim->time_die;
	while (philo->time_left > get_current_time()
		&& has_eaten_enough(philo) == 0)
		usleep(10);
	if (has_eaten_enough(philo) == 1)
		philo->time_left = -1;
	else
	{
		// philo->sim->philo_dead = philo->id;
		// philo->sim->death_time = get_current_time() - philo->sim->start_time;
		// printf("%lld\n", philo->sim->death_time);
		send_message(philo, DEAD);
		exit(3);
	}
	return (0);
}

void	insightful_dinner(t_simulation *sim, int i)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		sim->philo.id = i;
		sim->philo.time_left = get_current_time() + (long long)sim->time_die;
		if (sim->philo.id % 2 != 0)
			ft_usleep((int )(sim->time_eat - 10LL));
		pthread_create(&sim->philo.supervisor, NULL, &supervisor,
			(void *)&sim->philo);
		while (sim->philo.time_left > get_current_time())
		{
			eat(&sim->philo);
			send_message(&sim->philo, SLEEP);
			ft_usleep(sim->time_sleep);
			send_message(&sim->philo, THINK);
		}
		pthread_join(sim->philo.supervisor, NULL);
		sem_close(sim->semaphore);
		exit(0);
	}
	else
		sim->philos_pid[i] = pid;
}
