/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:33:47 by pietro            #+#    #+#             */
/*   Updated: 2023/03/03 08:33:54 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int		n;

	if (stack && stack->next)
	{
		n = stack->num;
		stack->num = stack->next->num;
		stack->next->num = n;
	}
}

void	sa(t_program *program)
{
	swap(program->a);
	program->moves++;
	ft_putstr("sa\n");
}

void	sb(t_program *program)
{
	swap(program->b);
	ft_putstr("sb\n");
	program->moves++;
}

void	ss(t_program *program)
{
	swap(program->a);
	swap(program->b);
	ft_putstr("ss\n");
	program->moves++;
}
