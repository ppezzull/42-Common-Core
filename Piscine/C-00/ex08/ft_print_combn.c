/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:31:22 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/19 22:09:35 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(char *nbr, int len, char final)
{
	int	i;

	i = 0;
	while (i <= len - 1)
	{
		write(1, &nbr[i], 1);
		i++;
	}
	if (nbr[0] != final)
		write(1, ", ", 2);
}

void	fill_nbr(char *nbr, int len)
{
	int	i;

	i = 0;
	while (i <= len - 1)
	{
		nbr[i] = i + '0';
		i++;
	}
}

void	next_nbr(char *nbr, int len, int len2, char gap)
{
	int	i;

	len--;
	i = 0;
	if (nbr[len] != gap)
	{
		nbr[len] += 1;
		while (i <= len2)
		{
			nbr[len + i + 1] = nbr[len + i] + 1;
			i++;
		}
	}
	else
	{
		gap -= 1;
		next_nbr(nbr, len, len2, gap);
	}
}

void	ft_print_combn(int n)
{
	char	nbr[20];
	char	*p_nbr;
	char	final;

	final = (10 - n) + '0';
	p_nbr = nbr;
	if (n > 0 & n < 10)
	{
		fill_nbr(p_nbr, n);
		while (nbr[0] != final)
		{
			print_nbr(p_nbr, n, final);
			next_nbr(p_nbr, n, n, '9');
		}
		print_nbr(p_nbr, n, final);
	}
}
