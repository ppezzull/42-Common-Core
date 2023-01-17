/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:34:01 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/21 18:19:25 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	buff;

	i = 0;
	while (i <= size - 1)
	{
		j = 0;
		while (j <= size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				buff = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = buff;
			}
			j++;
		}
		i++;
	}
}
