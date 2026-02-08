/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelahm <abdelahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:26:34 by abdelahm          #+#    #+#             */
/*   Updated: 2026/02/08 17:14:08 by abdelahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef SEP
#  define SEP '\n'
# endif

char	*get_next_line(int fd);
char	*read_and_store(int fd, char *stash);
char	*find_char(char *str, int c);
char	*join_strings(char *stash, char *buffer, size_t i, size_t j);
char	*clear_stash(char *stash);
size_t	str_length(char *str);
char	*extract_line(char *stash);
char	*update_stash(char *stash);

#endif
