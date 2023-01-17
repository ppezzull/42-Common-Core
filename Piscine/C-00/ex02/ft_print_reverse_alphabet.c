/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:37:37 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/19 20:35:00 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	lettera;

	lettera = 'z';
	while (lettera >= 'a' )
	{
		write(1, &lettera, 1);
		lettera--;
	}
}
