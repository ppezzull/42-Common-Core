/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_hundred_numbers_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:12:35 by ppezzull          #+#    #+#             */
/*   Updated: 2023/03/13 16:12:38 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	over_hundred_numbers_sort(t_program **program)
{
	int		*sorted_stack;
	int		key_idx;
	int		i;

	key_idx = (stack_size((*program)->a) / 8);
	sorted_stack = stack_into_sorted_lst((*program)->a);
	i = 0;
	while (i++ < 7)
		push_quarter_into_b(program, sorted_stack, key_idx * i);
	sort_last_a_quarter(program);
	while ((*program)->b)
	{
		put_stack_on_top_of_b(*program, get_max_idx((*program)->b));
		pa(*program);
	}
	free(sorted_stack);
}
