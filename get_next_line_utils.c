/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelahm <abdelahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:26:41 by abdelahm          #+#    #+#             */
/*   Updated: 2026/02/08 17:59:24 by abdelahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear_stash(char *stash)
{
	free(stash);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*find_char(char *str, int c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
			return ((char *)&str[index]);
		index++;
	}
	return (0);
}

char	*join_strings(char *stash, char *buffer, size_t i, size_t j)
{
	char	*joined;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (clear_stash(stash));
	joined = malloc(sizeof(char)
			* (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!joined)
		return (clear_stash(stash));
	if (stash)
		while (stash[++i] != '\0')
			joined[i] = stash[i];
	while (buffer[j] != '\0')
		joined[i++] = buffer[j++];
	joined[ft_strlen(stash) + ft_strlen(buffer)] = '\0';
	free(stash);
	return (joined);
}
