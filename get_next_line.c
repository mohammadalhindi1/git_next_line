/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:38:10 by malhendi          #+#    #+#             */
/*   Updated: 2025/09/05 17:57:16 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_nl(int fd, char **stash)
{
	char	*buf;
	ssize_t	br;
	char	*tmp;

	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (!ft_strchr(*stash, '\n'))
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
			return (free(buf), -1);
		if (br == 0)
			break ;
		buf[br] = '\0';
		tmp = ft_strjoin(*stash, buf);
		if (!tmp)
			return (free(buf), -1);
		free(*stash);
		*stash = tmp;
	}
	free(buf);
	return (0);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static void	trim_stash(char **stash)
{
	size_t	i;
	char	*rest;

	if (!*stash)
		return ;
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	rest = ft_substr(*stash, i, ft_strlen(*stash + i));
	free(*stash);
	*stash = rest;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash || read_to_nl(fd, &stash) < 0)
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	trim_stash(&stash);
	if (!line && stash)
		return (free(stash), stash = NULL, NULL);
	return (line);
}
