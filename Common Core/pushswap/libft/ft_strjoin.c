/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:30:25 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/21 11:30:29 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*united;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	united = (char *) malloc (sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (united == NULL)
		return (NULL);
	while (s1[j] != '\0')
		united[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		united[i++] = s2[j++];
	united[i] = '\0';
	free(s1);
	return (united);
}

