/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:13:06 by ppezzull          #+#    #+#             */
/*   Updated: 2023/01/31 17:13:08 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *out, ...);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_print_conversion(char flag, va_list *ap);
int		ft_nbr_len(int n);
void	ft_putnbr_script(int nb);
int		ft_putptr(unsigned long long ptr);
int		ft_hex(unsigned int nb, char *hex, unsigned int base);

#endif
