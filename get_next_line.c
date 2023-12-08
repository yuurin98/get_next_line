/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:21 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/12/08 19:41:57 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (line == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (line);
}

char	*until_endline(char *line)
{	
	char	*trimmed;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	trimmed = ft_substr(line, 0, i + 1);
	if (trimmed == NULL)
	{
		free(trimmed);
		return (NULL);
	}
	return (trimmed);
}

char	*new_line(char	*line)
{
	char	*find_newline;
	char	*new_start;

	find_newline = ft_strchr(line, '\n');
	if (find_newline == NULL)
	{
		free(line);
		return (NULL);
	}
	new_start = ft_substr(find_newline + 1, 0, ft_strlen(find_newline + 1));
	if (new_start == NULL)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (new_start);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &current_line, 0) < 0)
		return (NULL);
	line = get_line(fd, line);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	current_line = until_endline(line);
	line = new_line(line);
	return (current_line);
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
/*
*/