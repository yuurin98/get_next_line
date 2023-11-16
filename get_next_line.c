/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:21 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/11/16 15:18:40 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(const char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (0);
	while (str[++i] != '\0')
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*get_line(char **s)
{
	char	*line;
	char	*temp;
	int		i;

	if (*s == NULL)
		return (NULL);
	if (is_newline(*s))
	{
		i = 0;
		while ((*s)[i] != '\n')
			i++;
		line = ft_substr(*s, 0, i);
		temp = ft_strdup(*s + i + 1);
		free(*s);
		*s = temp;
	}
	else
	{
		line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*remaining;
	char		*next_line;
	int			bytes;

	remaining = NULL;
	next_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	if (!remaining)
		remaining = ft_strdup("");
	while (!is_newline(remaining))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (ft_strlen(remaining) == 0)
				return (NULL);
			next_line = remaining;
			remaining = NULL;
			return (next_line);
		}
		buffer[bytes] = '\0';
		remaining = ft_strjoin(remaining, buffer);
	}
	next_line = get_line(&remaining);
	return (next_line);
}

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	close(fd);
}