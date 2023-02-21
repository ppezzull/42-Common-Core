/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:07:58 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/20 18:08:01 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*out;

	if (nitems == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	out = malloc(nitems * size);
	if (!out)
		return (NULL);
	ft_bzero(out, nitems * size);
	return (out);
}
