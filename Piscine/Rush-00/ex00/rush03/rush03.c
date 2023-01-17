/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:27:15 by ntamiano          #+#    #+#             */
/*   Updated: 2022/10/15 17:12:11 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	line(int row, char head, char mid, char tail)
{
	int	i;

	i = 1;
	while (i <= row)
	{
		if (i == 1)
		{
			ft_putchar(head);
		}
		else if (i != row)
		{
			ft_putchar(mid);
		}
		else
		{
			ft_putchar(tail);
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (y <= 0 || x <= 0)
	{
		write(1, "ERROR: Invalid Input!\n", 23);
		write(1, "Insert only > 0 numbers!\n", 26);
	}
	else
	{	
		i = 1;
		while (i <= y)
		{
			if (i == 1)
				line(x, 'A', 'B', 'C');
			else if (i != y)
				line(x, 'B', ' ', 'B');
			else
				line(x, 'A', 'B', 'C');
			i++;
		}
	}
}
