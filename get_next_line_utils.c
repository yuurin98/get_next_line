/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:28 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/11/14 16:41:36 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*buffer;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	buffer = (char *)malloc(ft_strlen((char *)str) + 1);
	if (buffer == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		buffer[i] = str[i];
		i++;
	}
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	i = -1;
	j = 0;
	buffer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (buffer == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	while (s2[j] != '\0')
	{
		buffer[i] = s2[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
	return (buffer);
}
