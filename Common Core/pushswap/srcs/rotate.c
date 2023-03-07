/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:21:47 by pietro            #+#    #+#             */
/*   Updated: 2023/03/07 09:21:50 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*stack_tmp;
	int		n;

	n = (*stack)->num;
	stack_tmp = *stack;
	*stack = (*stack)->next;
	while (stack_tmp->next)
		stack_tmp = stack_tmp->next;
	stack_tmp->next = new_stack(n);
}

void	ra(t_program *program)
{
	if (stack_size(program->a) > 1)
	{
		rotate(&(program->a));
		ft_putstr("ra\n");
	}
}

void	rb(t_program *program)
{
	if (stack_size(program->b) > 1)
	{
		rotate(&(program->b));
		ft_putstr("rb\n");
	}
}

void	rr(t_program *program)
{
	if (stack_size(program->a) > 1 && \
		stack_size(program->b) > 1)
	{
		rotate(&(program->a));
		rotate(&(program->b));
		ft_putstr("rr\n");
	}
}
