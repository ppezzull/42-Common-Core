#include "../includes/philo.h"

void	eat(t_philosopher	*philo)
{
	t_philosopher *philo_friend;

	philo_friend = get_philo_friend(philo);
	pthread_mutex_lock(&philo->fork);
	send_message(philo, FORK);
	pthread_mutex_lock(&philo_friend->fork);
	send_message(philo, FORK);
	philo->time_left += (long long)philo->sim->time_die;
	send_message(philo, EAT);
	ft_usleep(philo->sim->time_eat);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo_friend->fork);
}

void *supervisor(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) argv;
	pthread_mutex_lock(&philo->time_mutex);
	while (philo->time_left - get_current_time() > 0)
		;
	pthread_mutex_unlock(&philo->time_mutex);
	pthread_mutex_lock(&philo->sim->lock);
	send_message(philo, DEAD);
	philo->sim->kill_switch = 1;
	pthread_mutex_unlock(&philo->sim->lock);
	return (0);
}

void	*eating_sesh(void *argv)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) argv;
	pthread_mutex_lock(&philo->time_mutex);
	philo->time_left = philo->sim->time_die + get_current_time();
	pthread_mutex_unlock(&philo->time_mutex);
	if (philo->id % 2 != 0)
		ft_usleep(10);
	pthread_create(&philo->supervisor, NULL, &supervisor, (void *)philo);
	pthread_detach(philo->supervisor);
	while  (philo->time_left - get_current_time() > 0 && 
			philo->sim->kill_switch != 1)
	{
		eat(philo);
		send_message(philo, SLEEP);
		ft_usleep(philo->sim->time_sleep);
		send_message(philo, THINK);
		// printf("time_left of %i -> %lld\n", philo->id, philo->time_left - get_current_time());
	}
	return (0);
}


void	start_simulation(t_simulation *sim)
{
	int i;

	i = 0;
	while (i < sim->philo_len)
	{
		pthread_create(&sim->philos[i].thread, NULL, &eating_sesh,
			(void *)&sim->philos[i]);
		i++;
	}
	i = 0;
	while (i < sim->philo_len)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
}