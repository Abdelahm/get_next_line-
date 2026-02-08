/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelahm <abdelahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:26:38 by abdelahm          #+#    #+#             */
/*   Updated: 2026/02/08 17:59:41 by abdelahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	int		index;
	char	*line;

	index = 0;
	if (!stash || !stash[index])
		return (NULL);
	while (stash[index] && stash[index] != SEP)
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != SEP)
	{
		line[index] = stash[index];
		index++;
	}
	if (stash[index] == SEP)
	{
		line[index] = stash[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	int		index;
	int		pos;
	char	*new_stash;

	index = 0;
	while (stash[index] && stash[index] != SEP)
		index++;
	if (!stash[index])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - index + 1));
	if (!new_stash)
		return (NULL);
	index++;
	pos = 0;
	while (stash[index])
		new_stash[pos++] = stash[index++];
	new_stash[pos] = '\0';
	free(stash);
	return (new_stash);
}

char	*read_and_store(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clear_stash(stash));
	bytes_read = 1;
	while (!find_char(stash, SEP) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (clear_stash(stash));
		}
		buffer[bytes_read] = '\0';
		stash = join_strings(stash, buffer, -1, 0);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_store(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	result = extract_line(stash);
	stash = update_stash(stash);
	if (!result && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (result);
}
