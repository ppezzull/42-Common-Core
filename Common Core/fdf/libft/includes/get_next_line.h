/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppezzull <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:09:27 by ppezzull          #+#    #+#             */
/*   Updated: 2023/02/07 17:09:29 by ppezzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft.h"

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*get_line(int fd, char *string);
char	*trim_line(char *str);

#endif

