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

char	*int_to_bin(int n)
{
	char	bin[9];
	int		bitshift;

	bitshift = 0;
	while (bitshift < 8)
	{
		if (n & 0x80 >> bitshift)
			bin[bitshift] = '1';
		else
			bin[bitshift] = '0';
		bitshift++;
	}
	bin[bitshift] = '\0';
	return (ft_strdup(bin));
}

void	semplify(t_stack *stack)
{
	int	
}

void	radix_sort(t_program **program)
{
	t_stack	*tmp;
	
	tmp = (*program)->a;
	semplify(tmp);
	print_bin_program(*program);
}
