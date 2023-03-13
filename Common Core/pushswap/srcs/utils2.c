/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:40:50 by pietro            #+#    #+#             */
/*   Updated: 2023/03/13 14:40:53 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_stack_on_top_of_a(t_program *program, int idx)
{
	int		len;

	len = stack_size(program->a);
	if (idx < len / 2)
	{
		while (idx--)
			ra(program);
	}
	else
	{
		while (idx < len)
		{
			rra(program);
			idx++;
		}
	}
}

void	put_stack_on_top_of_b(t_program *program, int idx)
{
	int		len;

	len = stack_size(program->b);
	if (idx < len / 2)
	{
		while (idx--)
			rb(program);
	}
	else
	{
		while (idx < len)
		{
			rrb(program);
			idx++;
		}
	}
}