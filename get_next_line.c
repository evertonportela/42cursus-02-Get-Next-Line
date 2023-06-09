/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:53:01 by evportel          #+#    #+#             */
/*   Updated: 2023/06/08 20:42:03 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	find_next_line(char *string)
{
	if (string == NULL)
		return (0);
	while (*string != '\0')
	{
		if (*string == '\n')
			return (1);
		string++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	buffer_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer_read = read(fd, buffer, BUFFER_SIZE);
	if (buffer_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[buffer_read] = '\0';
	if (find_next_line(buffer))
		return (buffer);
	return (buffer);
}
