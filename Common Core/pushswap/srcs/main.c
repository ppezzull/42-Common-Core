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

void    error(void)
{
    ft_putstr("Error\n");
    exit(EXIT_FAILURE);
}

t_program	*read_input(char *argv)
{
	t_program	*program;
	int			*lst;

	program = malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	lst = get_lst(argv)
	program->a = insert_into_stack(lst);
	return(program)
}

int	main(int argc, char **argv)
{
	t_program	program;

	program = read_input(argv[1]);
	if (!t_program)
		error()
}