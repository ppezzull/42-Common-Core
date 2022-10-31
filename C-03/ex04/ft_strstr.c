/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:32:56 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/26 19:44:14 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int main () 
// {
//     char haystack[] = "bella zi como va";
//     char needle[10] = "zi";
//     char *ret;

//     ret = strstr(haystack, needle);
//     // printf("strstr: %s\n", ret);

//     ret = ft_strstr(haystack, needle);
//     printf("ft_strstr: %s\n", ret);
// 	printf("%s\n", haystack);

//     return(0);
// }
