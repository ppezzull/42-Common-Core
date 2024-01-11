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
	if (get_current_time() + philo->sim->time_eat
		+ philo->sim->time_sleep == philo->time_left)
		ft_usleep(10);
	sem_wait(philo->sim->semaphore);
	send_message(philo, FORK);
	philo->is_eating = 1;
	philo->time_left = get_current_time() + (long long)philo->sim->time_die;
	send_message(philo, EAT);
	ft_usleep(philo->sim->time_eat);
	philo->is_eating = 0;
	philo->n_eat++;
	sem_post(philo->sim->semaphore);
	sem_post(philo->sim->semaphore);
}

void	*supervisor(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)argv;
	while (has_eaten_enough(philo) == 0
		&& (philo->time_left > get_current_time() || philo->is_eating == 1))
		ft_usleep(1);
	if (has_eaten_enough(philo) == 1)
		philo->time_left = -1;
	else
		exit(3);
	return (0);
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

void	insightful_dinner(t_simulation *sim, int i)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		sim->philo.id = i;
		sim->philo.time_left = get_current_time() + (long long)sim->time_die;
		if (sim->philo.id % 2 != 0)
			ft_usleep(sim->time_eat);
		pthread_create(&sim->philo.supervisor, NULL, &supervisor,
			(void *)&sim->philo);
		pthread_detach(sim->philo.supervisor);
		while (sim->philo.time_left > get_current_time())
			insightful_eating(&sim->philo);
		sem_close(sim->semaphore);
		exit(1);
	}
	else
		sim->philos_pid[i] = pid;
}
