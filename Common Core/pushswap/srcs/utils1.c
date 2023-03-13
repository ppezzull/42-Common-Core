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

void	print_stack(t_stack	*stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%i ", tmp->num);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	print_program(t_program *program)
{
	ft_putstr("a ");
	print_stack(program->a);
	ft_putstr("b ");
	print_stack(program->b);
}
