/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:13:12 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/26 19:13:46 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

// int main()
// {
//     char leftStr[] = "";
//     char rightStr[] = "bono";
//     int res;

//     res = strcmp(leftStr, rightStr);
//     printf("%i\n", res);

//     res = ft_strcmp(leftStr, rightStr);
//     printf("%i\n", res);
// }
