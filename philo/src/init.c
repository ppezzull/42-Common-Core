#include "../includes/philo.h"

t_philosopher *init_philos(t_simulation *sim)
{
  
}

void  init_simulation(t_simulation *sim, int argc, char **argv)
{
  sim->philo_nbr = ft_atoi(argv[1]);
  sim->time_die = ft_atoi(argv[2]);
  sim->time_eat = ft_atoi(argv[3]);
  sim->time_sleep = ft_atoi(argv[4]);
  if (argc == 6)
    sim->eat_goal = ft_atoi(argv[5]);
  else
    sim->eat_goal = -1;
  sim->philos = init_philos(sim);
}