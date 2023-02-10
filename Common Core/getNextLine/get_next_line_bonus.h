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

#ifndef GET_NEXT_LINE_BONUS_H
# define  GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*get_line(int fd, char *string);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int ch);
int		ft_strlen(const char *str);
char	*trim_line(char *str);

#endif
