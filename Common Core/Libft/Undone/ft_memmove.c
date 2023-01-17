/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:29:20 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/17 18:29:22 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *str1, const void *str2, int n);

int	main(int argc, char	**argv)
{
	char	*src;
	char	*dest;
	char	*dest2;
	int		n;

	dest = argv[1];
	dest2 = argv[1];
	n = atoi(argv[2]);
	printf("Before memcpy dest = %s\n", dest);
	memmove(dest + 3, dest, n);
	printf("memmove dest = %s\n", dest);
	// ft_memmove(dest2, src, n);
	// printf("ft_memmove dest = %s\n", dest2);
}