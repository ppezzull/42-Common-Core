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

#include "../includes/philo_bonus.h"

void	send_dead_message(t_simulation *sim)
{
	if (sim->death_time > 0)
		printf("%lld %i %s\n", sim->death_time, sim->philo_dead + 1, DEAD);
}

void	end_simulation(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->philo_len)
	{
		kill(sim->philos_pid[i], SIGKILL);
		i++;
	}
}

void	start_simulation(t_simulation *sim)
{
	int	status;
	int	i;

	i = 0;
	sim->start_time = get_current_time();
	while (i < sim->philo_len)
	{
		insightful_dinner(sim, i);
		i++;
	}
	i = 0;
	while (i < sim->philo_len)
	{
		waitpid(-1, &status, 0);
		if (WSTOPSIG(status) == 3)
		{
			sim->philo_dead = i;
			sim->death_time = get_current_time() - sim->start_time;
			end_simulation(sim);
		}
		i++;
	}
	sem_close(sim->semaphore);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;

	sem_unlink("/semfork");
	check_input(argc, argv);
	init_simulation(&sim, argc, argv);
	start_simulation(&sim);
	send_dead_message(&sim);
}
