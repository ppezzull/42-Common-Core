/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:50:54 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/20 17:50:55 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char	*s1;
	const char	*s2;

	s1 = (const char *)str1;
	s2 = (const char *)str2;
	if (!str1 || !str2)
		return (0);
	return (ft_strncmp(s1, s2, n));
}
