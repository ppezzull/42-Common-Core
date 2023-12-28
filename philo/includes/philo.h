/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:12:06 by ppezzull          #+#    #+#             */
/*   Updated: 2023/11/29 16:12:08 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS
# define PHILOSOPHERS

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
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	struct s_simulation	*sim;
	int					id;
	int					time_left;
	int					n_eat;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		l_fork;
	pthread_t			thread;
}						t_philosopher;

typedef struct s_simulation
{
	int					philo_nbr;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					eat_goal;
	int					start_time;
	t_philosopher		*philos;
}						t_simulation;

int						is_numeric(char *str);
int						ft_atoi(char *str);
int						get_current_time(void);
int						ft_usleep(int milliseconds);

void					check_input(int argc, char **argv);
void					print_instructions(void);
void					init_simulation(t_simulation *sim, int argc,
							char **argv);
void					start_simulation(t_simulation *sim);
void					send_message(t_philosopher *philo, char *message);

#endif