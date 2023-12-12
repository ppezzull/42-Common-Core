/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:01:51 by pietro            #+#    #+#             */
/*   Updated: 2023/03/08 23:01:54 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_lst(int *lst)
{
	int	i;

	if (lst)
	{
		i = -1;
		while (lst[i++])
			ft_printf("%i ", lst[i]);
	}
	ft_putchar_fd('\n', 1);
}
