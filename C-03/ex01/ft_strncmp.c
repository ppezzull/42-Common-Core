/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:21:39 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/26 19:24:19 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n & s1[i] == s2[i])
	{
		if (s1[i] == s2[i] & i == n - 1 || s1[i + 1] == 0)
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main()
// {
//     char s1[] = "abcdefgh", s2[] = "ok";
//     unsigned int n = 3;

//     printf("%i\n",strncmp(s1, s2, n));
//     printf("%i",ft_strncmp(s1, s2, n));
// }
