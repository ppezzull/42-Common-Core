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
	char				*bin;
	struct s_stack		*next;
}						t_stack;

typedef struct s_program
{
	t_stack				*a;
	t_stack				*b;
	int					moves;
}						t_program;

int			*stack_into_sorted_lst(t_stack *stack);
int			stack_size(t_stack *stack);
int			get_min_idx(t_stack *stack);
int			get_max_idx(t_stack *stack);

t_stack		*new_stack(int nb);
t_stack		*ft_stack_index(t_stack *stack, int i);

void		start_program(t_program **program, char **argv, int argc);
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
void		put_stack_on_top_of_a(t_program *program, int idx);
void		put_stack_on_top_of_b(t_program *program, int idx);
void		ten_numbers_sort(t_program **program);
void		three_numbers_sort(t_program **program);
void		hundred_numbers_sort(t_program **program, int chunks);
void		push_quarter_into_b(t_program **program, int b_len, int key_nbr);
void		sort_last_a_quarter(t_program **program);
void		stack_del(t_stack **stack);
void		radix_sort(t_program **program);


#endif
