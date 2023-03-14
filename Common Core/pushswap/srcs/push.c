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
	t_stack	*tmp;

	if (program->b)
	{
		tmp = program->a;
		program->a = new_stack(program->b->num);
		program->a->next = tmp;
		if (stack_size(program->b) == 1)
			program->b = NULL;
		else
			program->b = program->b->next;
		ft_putstr("pa\n");
	}
}

void	pb(t_program *program)
{
	t_stack	*tmp;

	if (program->a)
	{
		tmp = program->b;
		program->b = new_stack(program->a->num);
		program->b->next = tmp;
		if (stack_size(program->a) == 1)
			stack_del(&(program->a));
		else
		{
			tmp = program->a->next;
			free(program->a);
			program->a = tmp;
		}
		ft_putstr("pb\n");
	}
}
