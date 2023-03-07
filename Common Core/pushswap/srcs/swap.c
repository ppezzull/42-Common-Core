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
	int		tmp;

	if (stack)
	{
		n = ft_;
		tmp = stack_tmp->num;
		stack_tmp->num = stack_tmp->next->num;
		stack_tmp->next->num = tmp;
	}
}

void	sa(t_program *program)
{
	swap(program->a);
	ft_putstr("sa\n");
}

void	sb(t_program *program)
{
	swap(program->b);
	ft_putstr("sb\n");
}

void	ss(t_program *program)
{
	swap(program->a);
	swap(program->b);
	ft_putstr("ss\n");
}
