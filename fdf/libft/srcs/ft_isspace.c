/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:25:09 by pietro            #+#    #+#             */
/*   Updated: 2023/02/27 10:25:10 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(unsigned char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
