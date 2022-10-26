/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:06:34 by lfrancav          #+#    #+#             */
/*   Updated: 2022/10/18 08:07:11 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_char_to_hex(unsigned char str)
{
	int		i;
	char	h[2];

	h[0] = '0';
	i = str / 16;
	if (i < 10)
		h[0] = 48 + i;
	else
		h[0] = 87 + i;
	i = str % 16;
	if (i < 10)
		h[1] = 48 + i;
	else
		h[1] = 87 + i;
	write(1, "\\", 1);
	write (1, &h[0], 1);
	write (1, &h[1], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		c;

	c = 0;
	while (str[c] != 0)
	{
		if (str[c] == ' ' || (str[c] >= '!' && str[c] <= '~'))
			write(1, &str[c], 1);
		else
			write_char_to_hex(str[c]);
		c++;
	}
}
