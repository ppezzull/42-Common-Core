/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:17:17 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/20 18:02:09 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_from(char start1, char start2)
{
	char	c;
	char	e;

	c = start1;
	e = start2 + 1;
	while (c <= '9')
	{
		while (e <= '9')
		{
			write(1, &start1, 1);
			write(1, &start2, 1);
			write(1, " ", 1);
			write(1, &c, 1);
			write(1, &e, 1);
			if (start1 != '9' || start2 != '8' || start1 != c || start1 != e)
			{
				write(1, ", ", 2);
			}	
			e++;
		}
		e = '0';
		c++;
	}	
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	b = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			num_from(a, b);
			b++;
		}
		b = '0';
		a++;
	}
}
