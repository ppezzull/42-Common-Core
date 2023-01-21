/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:41:17 by marvin            #+#    #+#             */
/*   Updated: 2023/01/19 01:41:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

int     ft_isalpha(char letter);
int     ft_isdigit(int letter);
int     ft_isalnum(int letter);
int     ft_isascii(char letter);
int     ft_isprint(char letter);
int     ft_strlen(char* str);
void    *ft_memset(void *ptr, int x, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memcpy(void *dest, const void * src, size_t n);
void    *ft_memmove(void *dest, const void * src, size_t n);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
int     ft_toupper(int ch);
int     ft_tolower(int ch);
char    *ft_strchr(const char *str, int ch);
char    *ft_strrchr(const char *str, int ch);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
void    *ft_memchr(const void *str, int c, size_t n);
int     ft_memcmp(const void *str1, const void *str2, size_t n);
char 	*ft_strnstr (char *str, char *to_find, size_t len);
int	    ft_atoi(char *str);
void    *ft_calloc(size_t nitems, size_t size);
char    *ft_strdup(const char *src);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);

#endif