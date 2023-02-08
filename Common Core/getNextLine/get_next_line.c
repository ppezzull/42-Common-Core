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
	while (bytes != 0 && ft_strchr(string, '\n') == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes == 0)
		{
			free(buffer);
			return (string);
		}
		buffer[BUFFER_SIZE] = '\0';
		string = ft_strjoin(string, buffer);
		// printf("bytes	|%s|\n", string);
	}
	free(buffer);
	return (string);
}

char	*trim_line(char *str)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (str[len - 1] != '\n' && str[len] != '\0')
		len++;
	line = (char *) malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}

char	*cut_endl(char *string, char *line)
{
	if (!string)
		return (NULL);
	return (ft_strdup(string + (ft_strlen(line))));
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string = get_line(fd, string);
	if (!string)
		return (NULL);
	line = trim_line(string);
	string = cut_endl(string, line);
	return (line);
}
