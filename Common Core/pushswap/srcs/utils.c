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

int	get_min_idx(t_stack *stack)
{
	int		i;
	int		min;
	int		idx;
	t_stack	*tmp;

	tmp = stack;
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
	free(tmp);
	return (idx);
}

int	get_max_idx(t_stack *stack)
{
	int		i;
	int		max;
	int		idx;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	idx = 0;
	max = tmp->num;
	while (tmp)
	{
		if (tmp->num > max)
		{
			max = tmp->num;
			idx = i;
		}
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	return (idx);
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
	free(tmp);
	return (lst);
}

int	stack_size(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 1;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
