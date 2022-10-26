/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:55:14 by vpescete          #+#    #+#             */
/*   Updated: 2022/10/20 18:45:11 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *dest)
{
	int	count;

	count = 0;
	while (dest[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	c;
	int	i;

	i = 0;
	c = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[c] = src[i];
		c++;
		i++;
	}
	dest[c] = '\0';
	return (dest);
}
