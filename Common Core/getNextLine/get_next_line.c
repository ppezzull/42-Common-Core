/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pietro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:24:37 by pietro            #+#    #+#             */
/*   Updated: 2023/02/04 14:24:39 by pietro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *string)
{
	char	*buffer;
	size_t	bytes;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchr(string, '\n') == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes == -1)
		{
			free(buffer);
			return (string);
		}
		buffer[bytes] = '\0';
		string = ft_strjoin(string, buffer);
	}
	free(buffer);
	return (string);
}

char	*trim_line(char *str)
{
	int		len;
	char	*line;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	line = (char *) malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		line[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*cut_endl(char *string)
{
	int		j;
	int		len;
	char	*tmp;

	len = 0;
	while (string[len] && string[len] != '\n')
		len++;
	if (!string[len])
	{
		free(string);
		return (NULL);
	}
	tmp = (char *)malloc((ft_strlen(string) - len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	len++;
	j = 0;
	while (string[len])
		tmp[j++] = string[len++];
	tmp[j] = '\0';
	free(string);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string = get_line(fd, string);z
	if (!string)
		return (NULL);
	line = trim_line(string);
	string = cut_endl(string);
	return (line);
}
