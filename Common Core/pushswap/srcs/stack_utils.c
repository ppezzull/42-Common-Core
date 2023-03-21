/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:02:21 by pietro            #+#    #+#             */
/*   Updated: 2023/03/02 22:02:25 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_stack(int nb)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = nb;
	stack->next = NULL;
	return (stack);
}

void	stack_del(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_stack	*ft_stack_index(t_stack *stack, int i)
{
	int		j;
	t_stack	*tmp;

	if (i < 0)
		i += stack_size(stack);
	if (i < 0 || i >= stack_size(stack) || !stack)
		return (NULL);
	j = -1;
	tmp = stack;
	while (j++ <= i)
	{
		if (j == i)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	put_stack_on_top_of_a(t_program *program, int idx)
{
	int		len;

	len = stack_size(program->a);
	if (idx == 1)
		sa(program);
	else if (idx <= len / 2)
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
	if (idx == 1)
		sb(program);
	else if (idx <= len / 2)
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
