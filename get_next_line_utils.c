/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:28 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/12/06 14:29:08 by lchee-ti         ###   ########.fr       */
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
	buffer[i] = '\0';
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = 0;
	while (i + 1 < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	while (src[slen] != '\0')
		slen++;
	return (slen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	slen;
	size_t	sublen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen || len == 0)
		return (ft_strdup(""));
	sublen = len;
	if (start + len > slen)
		sublen = slen - start;
	substring = (char *)malloc(sizeof(char) * sublen + 1);
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, sublen + 1);
	return (substring);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (c > 255)
			c -= 256;
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}