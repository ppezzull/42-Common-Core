/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:05:25 by vpescete          #+#    #+#             */
/*   Updated: 2022/10/20 18:08:25 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	count;

	count = 0;
	j = 0;
	while (dest[count] != '\0')
	{
		count++;
	}
	while (j < nb && src[j] != '\0')
	{
		dest[count] = src[j];
		j++;
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
