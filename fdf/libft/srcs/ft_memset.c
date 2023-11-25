/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:49:12 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/20 17:49:15 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	char	*str;
	int		i;

	str = ptr;
	i = 0;
	while (n--)
	{
		str[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}
