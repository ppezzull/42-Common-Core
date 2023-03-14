/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:10:59 by ppezzull          #+#    #+#             */
/*   Updated: 2023/03/14 22:11:01 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack	*stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%i ", tmp->num);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	print_program(t_program *program)
{
	ft_putstr("a ");
	print_stack(program->a);
	ft_putstr("b ");
	print_stack(program->b);
}
