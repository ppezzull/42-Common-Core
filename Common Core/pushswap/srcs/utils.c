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

void	print_stack(t_stack	*stack)
{
	if (stack)
	{
		while (stack)
		{
			ft_printf("%i ", stack->num);
			if (stack->next)
				stack = stack->next;
			else
				break ;
		}
	}
	ft_putchar('\n');
}

int	stack_size(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_stack	*ft_stack_index(t_stack *stack, int i)
{
	int		j;
	t_stack	*stack_tmp;

	if (i < 0)
		i += stack_size(stack);
	if (i < 0 || i >= stack_size(stack) || !stack)
		return (NULL);
	j = -1;
	stack_tmp = stack;
	while (j++ <= i)
	{
		if (j == i)
			break ;
		stack_tmp = stack_tmp->next;
	}
	return (stack_tmp);
}

void	print_program(t_program *program)
{
	ft_putstr("a ");
	print_stack(program->a);
	ft_putstr("b ");
	print_stack(program->b);
}
