/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcapalbo <mcapalbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:57:37 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/29 22:51:17 by mcapalbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	init_simulation(t_simulation *sim, int argc, char **argv)
{
	sim->philo_len = ft_atoi(argv[1]);
	sim->time_die = ft_atoi(argv[2]);
	sim->time_eat = ft_atoi(argv[3]);
	sim->time_sleep = ft_atoi(argv[4]);
	sim->death_time = -1;
	sim->semaphore = sem_open("/semfork", O_CREAT, 0660, sim->philo_len);
	sim->philo.sim = sim;
	sim->philo.is_eating = 0;
	sim->philo.n_eat = 0;
	if (argc == 6)
		sim->eat_goal = ft_atoi(argv[5]);
	else
		sim->eat_goal = -1;
}
