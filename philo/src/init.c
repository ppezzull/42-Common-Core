/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:57:37 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/28 09:57:39 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philosopher *init_philos(t_simulation *sim)
{
  t_philosopher *philos;
  int           i;

  philos = (t_philosopher *) malloc(sim->philo_nbr * sizeof(t_philosopher));
  printf("%i\n", sim->philo_nbr);
  i = 0;
  while (i < sim->philo_nbr)
  {
    philos[i].sim = sim;
    philos[i].id = i + 1;
    philos[i].time_left = sim->time_die;
    philos[i].n_eat = 0;
    pthread_mutex_init(&philos[i].r_fork, NULL);
    if (i == sim->philo_nbr - 1)
      philos[i].l_fork = philos[0].r_fork;
    else
      philos[i].l_fork = philos[i + 1].r_fork;;
    i++;
  }
  return (philos);
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
  sim->start_time = get_current_time(); 
}
