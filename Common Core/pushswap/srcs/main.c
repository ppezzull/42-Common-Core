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

t_stack	*argv_into_stack(char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack_tmp;

	i = 0;
	if (!ft_atoi(argv[i]))
		argv = ft_split(argv[1], ' ');
	else
		i++;
	stack = new_stack(ft_atoi(argv[i]));
	stack_tmp = stack;
	while (argv[i++ + 1])
	{
		stack_tmp->next = new_stack(ft_atoi(argv[i]));
		stack_tmp = stack_tmp->next;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_program	*program;

	if (argc == 1)
		error();
	program = malloc(sizeof(t_program));
	if (!program)
		error();
	program->a = argv_into_stack(argv);
	print_program(program);
	// push_swap(program);
	sa(program);
	print_program(program);
}
