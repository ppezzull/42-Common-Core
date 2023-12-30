/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:12:42 by ppezzull          #+#    #+#             */
/*   Updated: 2023/11/29 16:12:44 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void free_simulation(t_simulation  *sim)
{
  int i;

  i = 0;
  while (i < sim->philo_len)
  {
    pthread_mutex_destroy(&sim->philos[i].fork);
    i++;
  }
}

int main(int argc, char **argv)
{
  t_simulation  sim;

  check_input(argc, argv);
  init_simulation(&sim, argc, argv);
  start_simulation(&sim);
  // free_simulation(&sim);

  // printf("%lld\n", sim.start_time);
  // printf("%lld\n", get_current_time());
  // ft_usleep(1000);
  // printf("%lld\n", get_current_time());
}
