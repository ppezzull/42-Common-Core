/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:54:16 by lfrancav          #+#    #+#             */
/*   Updated: 2022/10/18 07:55:44 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < 32 || str[c] > 127)
			return (0);
		c++;
	}
	return (1);
}
