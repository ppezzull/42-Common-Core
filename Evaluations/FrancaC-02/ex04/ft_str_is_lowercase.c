/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:50:09 by lfrancav          #+#    #+#             */
/*   Updated: 2022/10/18 07:53:34 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		c;

	c = 0;
	while (str[c])
	{
		if (!(str[c] >= 'a' && str[c] <= 'z'))
			return (0);
		c++;
	}
	return (1);
}
