#include "../includes/philo.h"

void	*routine(void *philosopher)
{
	send_message((t_philosopher *)philosopher, EAT);
	return (0);
}

void	start_simulation(t_simulation *sim)
{
	int i;

	i = 0;
	while (i < sim->philo_nbr)
	{
		pthread_create(&sim->philos[i].thread, NULL, &routine,
			(void *)&sim->philos[i]);
		i++;
	}
	i = 0;
	while (i < sim->philo_nbr)
	{
		pthread_join(sim->philos[i].thread, NULL);
		i++;
	}
	free(sim->philos);
}