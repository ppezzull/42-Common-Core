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

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);
int	    ft_putchar(int c);
int	    ft_putnbr(int nb);
int	    ft_putstr(char *str);
int     ft_putuint(unsigned int n);
int     ft_print_conversion(char flag, va_list *ap);

int     ft_nbr_len(int n);
int     ft_uint_len(unsigned int n);
void	ft_putnbr_script(int nb);
void	ft_putuint_script(unsigned int n);

#endif
