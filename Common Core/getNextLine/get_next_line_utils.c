/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:24:52 by pietro            #+#    #+#             */
/*   Updated: 2023/02/04 14:24:54 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int readline(int fd, char* buf)
{
    char source[1000000];

    FILE *fp = fopen("TheFile.txt", "r");
    if(fp != NULL)
    {
        while((symbol = getc(fp)) != EOF)
        {
            ft_strcat(source, &symbol);
        }
        fclose(fp);
    }
    printf("%s\n", source);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}