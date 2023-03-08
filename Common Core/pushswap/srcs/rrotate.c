/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:25:43 by pietro            #+#    #+#             */
/*   Updated: 2023/03/07 10:25:45 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = new_stack(ft_stack_index(*stack, -1)->num);
	(*stack)->next = tmp;
	ft_stack_index(*stack, -2)->next = NULL;
}

void	rra(t_program *program)
{
	if (stack_size(program->a) > 1)
	{
		rrotate(&(program->a));
		ft_putstr("rra\n");
	}
}

void	rrb(t_program *program)
{
	if (stack_size(program->b) > 1)
	{
		rrotate(&(program->b));
		ft_putstr("rrb\n");
	}
}

void	rrr(t_program *program)
{
	if (stack_size(program->a) > 1 && \
		stack_size(program->b) > 1)
	{
		rrotate(&(program->a));
		rrotate(&(program->b));
		ft_putstr("rrr\n");
	}
}
