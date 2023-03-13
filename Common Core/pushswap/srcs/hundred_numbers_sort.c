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

void	push_quarter_into_b(t_program **program, int *sorted_stack, int key_idx)
{
	int	i;
	int	n;

	i = 0;
	while (i < stack_size((*program)->a))
	{
		n = ft_stack_index((*program)->a, i)->num;
		if (n <= sorted_stack[key_idx - 1])
		{
			put_stack_on_top_of_a(*program, i);
			pb(*program);
			i = 0;
		}
		i++;
	}
}

void	sort_last_a_quarter(t_program **program)
{
	int		i;
	int		b_len;

	i = 0;
	while (stack_size((*program)->a) > 3)
	{
		put_stack_on_top_of_a(*program, get_min_idx((*program)->a));
		pb(*program);
		i++;
	}
	three_numbers_sort(program);
	b_len = i;
	i = -1;
	while (i++ < b_len - 1)
		pa(*program);
}

void	hundred_numbers_sort(t_program **program)
{
	int		*sorted_stack;
	int		key_idx;
	int		i;

	key_idx = (stack_size((*program)->a) / 4);
	sorted_stack = stack_into_sorted_lst((*program)->a);
	i = 0;
	while (i++ < 3)
		push_quarter_into_b(program, sorted_stack, key_idx * i);
	sort_last_a_quarter(program);
	while ((*program)->b)
	{
		put_stack_on_top_of_b(*program, get_max_idx((*program)->b));
		pa(*program);
	}
}
