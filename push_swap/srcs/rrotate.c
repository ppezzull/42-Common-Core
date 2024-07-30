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
	t_stack	*copy;
	t_stack	*tmp;
	int		i;
	int		len;

	len = stack_size(*stack);
	copy = new_stack(ft_stack_index(*stack, -1)->num);
	tmp = copy;
	i = -1;
	while (i++ < len - 2)
	{
		tmp->next = new_stack(ft_stack_index(*stack, i)->num);
		tmp = tmp->next;
	}
	stack_del(stack);
	*stack = copy;
}

void	rra(t_program *program)
{
	if (stack_size(program->a) > 1)
	{
		rrotate(&(program->a));
		ft_putstr("rra\n");
		program->moves++;
	}
}

void	rrb(t_program *program)
{
	if (stack_size(program->b) > 1)
	{
		rrotate(&(program->b));
		ft_putstr("rrb\n");
		program->moves++;
	}
}

void	rrr(t_program *program)
{
	if (stack_size(program->a) > 1 && stack_size(program->b) > 1)
	{
		rrotate(&(program->a));
		rrotate(&(program->b));
		ft_putstr("rrr\n");
		program->moves++;
	}
}
