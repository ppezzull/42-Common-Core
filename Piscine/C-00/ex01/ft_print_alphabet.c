/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:41:09 by ppezzull          #+#    #+#             */
/*   Updated: 2022/10/19 20:30:58 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	lettera;

	lettera = 'a';
	while (lettera <= 'z')
	{
		write(1, &lettera, 1);
		lettera++;
	}
}
