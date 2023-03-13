/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:34:43 by pietro            #+#    #+#             */
/*   Updated: 2023/02/17 16:34:46 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	start_program(t_program **program, char **argv, int argc)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i++;
	(*program)->a = new_stack(ft_atoi(argv[i]));
	tmp = (*program)->a;
	while (argv[i++ + 1])
	{
		tmp->next = new_stack(ft_atoi(argv[i]));
		tmp = tmp->next;
	}
	(*program)->b = NULL;
}

int	main(int argc, char **argv)
{
	t_program	*program;

	if (argc == 1)
		error();
	program = malloc(sizeof(t_program));
	if (!program)
		error();
	start_program(&program, argv, argc);
	push_swap(program);
	// printf("%i\n", get_max_idx(program->a));
	print_program(program);
}
