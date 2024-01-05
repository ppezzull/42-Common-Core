/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:38:02 by ppezzull          #+#    #+#             */
/*   Updated: 2023/12/30 12:38:05 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	fail(char *error)
{
	printf("%s%s\n", RED, error);
	printf("%s%s\n", WHITE, ARGV_LST);
	printf("%s\n%s\n%s\n%s\n%s\n", ARGV_1, ARGV_2, ARGV_3, ARGV_4, ARGV_5);
	exit(EXIT_FAILURE);
}

void	check_input(int argc, char **argv)
{
	int	i;

	if (argc > 6)
		fail(ERROR_1);
	if (argc < 5)
		fail(ERROR_2);
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < 0)
			fail(ERROR_3);
		if (is_numeric(argv[i]) == 0)
			fail(ERROR_4);
		i++;
	}
}
