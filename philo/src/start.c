#include "../includes/philo.h"

int get_philo_friend(int philo_id)
{
	if (philo_id - 2 < 0)
		return(0);
	else
		return(philo_id - 2);
}

void	*eating_sesh(void *argv)
{
	t_philosopher	*philo;
	// int 			idx;

	philo = (t_philosopher *) argv;
	// idx = get_philo_friend(philo->id);
	while (1)
	{	
		
		send_message(philo, "sto a magna diocane");
		ft_usleep(philo->sim->time_eat);
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