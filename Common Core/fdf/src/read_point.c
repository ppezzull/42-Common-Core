/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <ppezzull@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:44:53 by ppezzull          #+#    #+#             */
/*   Updated: 2023/11/04 14:44:55 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int hexStringToValue(const char* hexString) {
    unsigned int result = 0;
    int i = 0;

    // Check for "0x" prefix and skip if present
    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X')) {
        i = 2;
    }

    // Iterate through the string and convert each character to the integer value
    while (hexString[i] != '\0') {
        char c = hexString[i];
        unsigned int digitValue = 0;

        if (c >= '0' && c <= '9') {
            digitValue = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digitValue = 10 + c - 'A';
        } else if (c >= 'a' && c <= 'f') {
            digitValue = 10 + c - 'a';
        } else {
            // Invalid character in the string
            printf("Invalid character in the string: %c\n", c);
            return 0;
        }

        result = (result << 4) | digitValue; // Shift and bitwise OR to accumulate the value
        i++;
    }

    return result;
}

void    read_point(char *point, t_point *a)
{
    char    **info;
    char    *color_str;

    if (ft_strchr(point, ','))
    {
        info = ft_split(point, ',');
        a->z = ft_atoi(info[0]);
        color_str = info[1];
        a->color = hexStringToValue(color_str);
        free(info[0]);
        free(info[1]);
        free(info);
    }
    else
    {
        a->color = LIGHT_PURPLE;
        a->z = ft_atoi(point);
    }
}