/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:44:12 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/11/08 16:44:13 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	buffer = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (buffer == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	while (s2[j] != '\0')
		buffer[i++] = s2[j++];
	buffer[i] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (*s == '\0')
		return (NULL);
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
