/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:44:26 by pietro            #+#    #+#             */
/*   Updated: 2023/03/08 22:44:27 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_idx(t_program *program)
{
	int		i;
	int		min;
	int		idx;
	t_stack	*tmp;

	tmp = program->a;
	i = 0;
	idx = 0;
	min = tmp->num;
	while (tmp)
	{
		if (tmp->num < min)
		{
			min = tmp->num;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (idx);
}

void	min_on_top(t_program *program)
{
	int	len;
	int	idx;

	idx = min_idx(program);
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	buff;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				buff = tab [i];
				tab[i] = tab [i + 1];
				tab [i + 1] = buff;
			}
			i++;
		}
		size--;
	}
}

int	*stack_into_sorted_lst(t_stack *stack)
{
	int		*lst;
	int		i;
	int		len;
	t_stack	*tmp;

	len = stack_size(stack);
	lst = malloc(sizeof(int) * len);
	if (!lst)
		error();
	i = 0;
	tmp = stack;
	while (tmp)
	{
		lst[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(lst, len);
	return (lst);
}
