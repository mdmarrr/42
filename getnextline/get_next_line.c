/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magomez- <magomez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:43:34 by magomez-          #+#    #+#             */
/*   Updated: 2025/12/09 13:24:35 by magomez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_set_line(char *line_buffer)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	stash = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line_buffer[i + 1] = 0;
	return (stash);
}

char	*_fill_line_buffer(int fd, char *stash, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, stash, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = _set_line(line);
	return (line);
}

/*
char	*_fill_line_buffer(int fd, char *stash)
{
	ssize_t		bytes_read;
	char		*buffer;
	char		*tmp;

	bytes_read = 1;
	buffer = (char *)malloc((BUFFER_SIZE +1) * sizeof(char));
	while ((stash == NULL || !ft_strchr(stash, '\n')) && bytes_read > 0)
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
			stash = ft_strdup(buffer);
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
	stash = _set_line(line);
	return (line);
}
*/