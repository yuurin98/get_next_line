/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:21 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/12/06 16:20:00 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char	*line)
{
	char	*new_start;

	new_start = ft_strchr(line, '\n');
	if (new_start == NULL)
		return (NULL);
}

char	*get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = (char *)malloc()
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
	}
	return (line);
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
	current_line = line_trim(line);
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