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

int main(int argc, char **argv)
{
  t_simulation  sim;

  check_input(argc, argv);
  init_simulation(&sim, argc, argv);
  //free(sim);
}
