/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_numbers_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:25:55 by ppezzull          #+#    #+#             */
/*   Updated: 2023/03/08 22:25:57 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_quarter_into_b(t_program **program, int b_len, int key_nbr)
{
	t_stack	*tmp;
	int		i;

	tmp = (*program)->a;
	i = 0;
	while (stack_size((*program)->b) < b_len && tmp)
	{
		if (tmp->num <= key_nbr)
		{
			put_stack_on_top_of_a(*program, i);
			pb(*program);
			i = 0;
			tmp = (*program)->a;
		}
		tmp = tmp->next;
		i++;
	}
}

void	sort_last_a_quarter(t_program **program)
{
	while (stack_size((*program)->a) > 3)
	{
		put_stack_on_top_of_a(*program, get_min_idx((*program)->a));
		print_stack((*program)->a);
		pb(*program);
	}
	three_numbers_sort(program);
}
