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

int	is_found(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (to_find[j] != 0)
	{
		if (to_find[j] != str[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	len(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*append_str(char *str, char *to_find, int i)
{
	int	j;

	j = len(to_find);
	i += len(to_find);
	while (str[i] != '\0')
	{
		to_find[j] = str[i];
		i++;
		j++;
	}
	to_find[j] = 0;
	return (to_find);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			found = is_found(str, to_find, i);
			if (found)
			{
				append_str(str, to_find, i);
				return (to_find);
			}
		}
		i++;
	}
	return (0);
}

// int main () {
//     char haystack[] = "point";
//     char needle[10] = "";
//     char *ret;

//     ret = strstr(haystack, needle);
//     printf("strstr: %s\n", ret);

//     ret = ft_strstr(haystack, needle);
//     printf("ft_strstr: %s\n", ret);

//     return(0);
// }
