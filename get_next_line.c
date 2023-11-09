/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:21 by lchee-ti          #+#    #+#             */
/*   Updated: 2023/11/09 15:47:15 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*nextline;

	if (fd < 0 || BUFFER SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
}
