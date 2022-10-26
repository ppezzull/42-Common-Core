/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpescete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:36:17 by vpescete          #+#    #+#             */
/*   Updated: 2022/10/20 18:42:33 by vpescete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s2[i] == '\0' || s1[i] == '\0')
		return (s1[i] - s2[i]);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			return (s1[i] - s2[i]);
		}
	}
}

int main()
{
	printf("%i", ft_strcmp("ciao", "ciao"));
	printf("%i", ft_strcmp("ciao fre", "ciao"));
	printf("%i", ft_strcmp("hi", "ciao"));
}