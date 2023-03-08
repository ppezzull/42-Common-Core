/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:15:44 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/17 21:15:45 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <sys/types.h>

typedef struct s_stack
{
	int					num;
	struct s_stack		*next;
}						t_stack;

typedef struct s_program
{
	t_stack				*a;
	t_stack				*b;
}						t_program;

int			stack_size(t_stack *stack);

t_stack		*new_stack(int nb);
t_stack		*argv_into_stack(char **argv, int argc);
t_stack		*ft_stack_index(t_stack *stack, int i);

void		error(void);
void		print_stack(t_stack	*stack);
void		print_program(t_program *program);
void		sa(t_program *program);
void		sb(t_program *program);
void		ss(t_program *program);
void		swap(t_stack *stack);
void		pa(t_program *program);
void		pb(t_program *program);
void		ra(t_program *program);
void		rb(t_program *program);
void		rr(t_program *program);
void		rotate(t_stack **stack);
void		rra(t_program *program);
void		rrb(t_program *program);
void		rrr(t_program *program);
void		rrotate(t_stack **stack);
void		push_swap(t_program *program);
void		three_numbers_sort(t_program **program);
void		ten_numbers_sort(t_program **program);
void		min_on_top(t_stack *stack);

#endif
