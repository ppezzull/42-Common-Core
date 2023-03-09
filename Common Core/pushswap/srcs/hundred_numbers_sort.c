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

void	hundred_numbers_sort(t_program **program)
{
	int	*sorted_stack;
	int	chunks;
	int	key_idx;
	int	i;
	int	j;

	key_idx = stack_size((*program)->a) / 4;
	sorted_stack = stack_into_sorted_lst((*program)->a);
	// for (int i = 0; sorted_stack[i]; i++)
	//  	printf("%i ", sorted_stack[i]);
	i = 3;
	while (i--)
	{
		j = -1;
		while (j++ < stack_size((*program)->a) / 4)
		{
			put_stack_on_top(*program, key_idx);
			pb(*program);
		}
		key_idx += key_idx;
	}
}
