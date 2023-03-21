/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:14:51 by ppezzull          #+#    #+#             */
/*   Updated: 2023/03/21 20:14:53 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	semplify(int *sorted, t_stack *stack)
// {

// }

int	*get_sort_index(t_stack *stack)
{
	int	*sorted;
	int	i;
	int	j;
	// int	n;
	int	len;

	sorted = stack_into_sorted_lst(stack);
	len = stack_size(stack) - 1;
	i = -1;
	while (i++ < len)
	{
		j = -1;
		while (j++ < len)
			printf("%i %i\n", sorted[i], sorted[j]);
	}
	printf("ok\n");
	return (sorted);
}

void	convert_to_bin(t_stack *stack)
{
	int		*ez_sorted;
	t_stack	*tmp;

	ez_sorted = get_sort_index(stack);
	tmp = stack;
	printf("stack len %i\n", stack_size(tmp));
}

void	radix_sort(t_program **program)
{
	convert_to_bin((*program)->a);
}
