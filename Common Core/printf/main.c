/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pezzu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:07:58 by pezzu             #+#    #+#             */
/*   Updated: 2023/02/03 06:08:11 by pezzu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char **argv)
{
    int     len;
    int     len2;
    int     n;
    
    n = atoi(argv[1]);
    len = ft_printf("%p\n", n);
    // len2 = printf("%p\n", n);
    printf(
        "ft_printf   len %i\nprintf      len %i\n",
        len,
        len2
    );
}

// • %s Prints a string (as defined by the common C convention). DONE 10.SIGSEGV
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
