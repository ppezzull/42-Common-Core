/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrancav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:02:55 by lfrancav          #+#    #+#             */
/*   Updated: 2022/10/18 08:05:29 by lfrancav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		c;

	c = 0;
	while (str[c])
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			str[c] += 32;
		c++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		c;
	int		check;

	str = ft_strlowcase(str);
	c = 0;
	check = 0;
	if (str[0] >= 'a' && str[0] <= 'z')
	{	
		str[0] -= 32;
		c++;
	}
	while (str[c] != '\0')
	{
		if ((str[c] >= 'a' && str[c] <= 'z') || (str[c] >= '0' && str[c] <= '9'))
		{
			if (check)
			{
				check = 0;
				if (str[c] >= 'a' && str[c] <= 'z')
					str[c] -= 32;
			}
		}
		else
			check = 1;
		c++;
	}
	return (str);
}