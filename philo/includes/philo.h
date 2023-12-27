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

#define INT_MAX 2147483647

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_philosopher
{
  t_simulation	*sim;

} t_philosopher;

typedef struct s_simulation
{
  	int				philo_nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_goal;
	t_philosopher   *philos;
} t_simulation;


int   is_numeric(char *str);
int   ft_atoi(char *str);

void  check_input(int argc, char **argv);
void  print_instructions(void);

void init_simulation(t_simulation *sim, int argc, char **argv);

#endif