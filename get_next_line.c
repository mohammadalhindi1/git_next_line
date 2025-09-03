
#include "get_next_line.h"

static int	read_to_nl(int fd, char **stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	br;
	char	*tmp;

	while (!ft_strchr(*stash, '\n'))
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
			return (-1);
		if (br == 0)
			break ;
		buf[br] = '\0';
		tmp = ft_strjoin(*stash, buf);
		if (!tmp)
			return (-1);
		if (*stash)
			free(*stash);
		*stash = tmp;
	}
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
