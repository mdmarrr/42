/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:43:34 by magomez-          #+#    #+#             */
/*   Updated: 2025/12/01 15:07:55 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_fill_line_buffer(int fd, char *stash)
{
	ssize_t		bytes_read;
	char		*buffer;
	char		*tmp;

	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE +1) * sizeof(char));
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

char	*_set_line(char *line)
{
	char	*stash;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	if (line[i] == '\n')
		i++;
	stash = ft_substr(line, i, ft_strlen(line) - i);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = _fill_line_buffer(fd, stash);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_strdup(stash);
	free(stash);
	stash = _set_line(line);
	return (line);
}
