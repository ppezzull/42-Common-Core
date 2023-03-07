/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:39:12 by pietro            #+#    #+#             */
/*   Updated: 2023/03/03 10:39:15 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_program *program)
{
	t_stack	*stack_tmp;

	if (program->b)
	{
		stack_tmp = program->a;
		program->a = new_stack(program->b->num);
		program->a->next = stack_tmp;
		if (stack_size(program->b) == 1)
			program->b = NULL;
		else
			program->b = program->b->next;
		ft_putstr("pa\n");
	}
}

void	pb(t_program *program)
{
	t_stack	*stack_tmp;

	if (program->a)
	{
		stack_tmp = program->b;
		program->b = new_stack(program->a->num);
		program->b->next = stack_tmp;
		if (stack_size(program->a) == 1)
			program->a = NULL;
		else
			program->a = program->a->next;
		ft_putstr("pb\n");
	}
}