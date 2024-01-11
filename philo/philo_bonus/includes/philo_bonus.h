/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:36:34 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/30 12:36:39 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define INT_MAX 2147483647

# define RED "\x1b[31m"
# define WHITE "\x1b[0m"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

# define ARGV_LST "These are the parameters:"
# define ARGV_1 "-number_of_philosophers"
# define ARGV_2 "-time_to_die"
# define ARGV_3 "-time_to_eat"
# define ARGV_4 "-time_to_sleep"
# define ARGV_5 "-[number_of_times_each_philosopher_must_eat]"

# define ERROR_1 "Too Many Arguments!"
# define ERROR_2 "Too Few Arguments!"
# define ERROR_3 "Values out of range!"
# define ERROR_4 "You need to put numeric values!"

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

typedef struct s_philosopher
{
	struct s_simulation	*sim;
	long long			time_left;
	int					id;
	int					n_eat;
	int					is_eating;
	pthread_t			supervisor;
}						t_philosopher;

typedef struct s_simulation
{
	int					philo_len;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					eat_goal;
	int					philo_dead;
	int					philos_pid[200];
	sem_t				*semaphore;
	long long			death_time;
	long long			start_time;
	t_philosopher		philo;
}						t_simulation;

t_philosopher			*get_philo_friend(t_philosopher *philo);

int						is_numeric(char *str);
int						ft_atoi(char *str);
int						has_eaten_enough(t_philosopher *philo);

long long				get_current_time(void);

void					ft_usleep(int milliseconds);
void					check_input(int argc, char **argv);
void					print_instructions(void);
void					init_simulation(t_simulation *sim, int argc,
							char **argv);
void					start_simulation(t_simulation *sim);
void					send_message(t_philosopher *philo, char *message);
void					kill_philos(t_simulation *sim);
void					end_simulation(t_simulation *sim);
void					insightful_dinner(t_simulation	*sim, int i);
void					*supervisor(void *argv);

#endif
