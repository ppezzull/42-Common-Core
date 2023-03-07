/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:48:42 by pietro            #+#    #+#             */
/*   Updated: 2023/03/07 15:48:43 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers_sort(t_program **program)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = ft_stack_index((*program)->a, 0)->num;
	n2 = ft_stack_index((*program)->a, 1)->num;
	n3 = ft_stack_index((*program)->a, 2)->num;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(*program);
	else if (n1 < n2 && n2 > n3 && n3 < n1)
		rra(*program);
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(*program);
	else if (n1 < n2 && n2 > n3 && n3 > n1)
	{
		sa(*program);
		ra(*program);
	}
	else if (n3 > n2 && n2 > n1 && n3 < n1)
	{
		sa(*program);
		rra(*program);
	}
}

void	push_swap(t_program *program)
{
	if (stack_size(program->a) == 3)
		three_numbers_sort(&program);
}
