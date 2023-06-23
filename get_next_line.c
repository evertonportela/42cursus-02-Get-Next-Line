/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:50 by evportel          #+#    #+#             */
/*   Updated: 2023/06/13 19:15:50 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*free_work_memories(char **mem_line, char **mem_rest,
				char **mem_buffer);
static char	*get_only_line(char **rest_content, char **buffer, char **line,
				int buffer_read);
static char	*content_after_line(char *content);
static char	*content_before_break_line(char *content);

char	*get_next_line(int fd)
/**
* Reads from a file descriptor and returns one line read per call,
* including \n unless EOF (find end of file)
* and no \n is present,
* in this case everything that was read is returned immediately.
*/
{
	static char	*rest_content;
	char		*line;
	char		*buffer;
	int			buffer_read;

	if (!rest_content)
		rest_content = ft_strdup("");
	line = ft_strdup(rest_content);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer_read = BUFFER_SIZE;
	while (buffer_read == BUFFER_SIZE && (line_break_position(line) < 0))
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read < 0)
			return (free_work_memories(&line, &rest_content, &buffer));
		buffer[buffer_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (get_only_line(&rest_content, &buffer, &line, buffer_read));
}

static void	*free_work_memories(char **mem_line, char **mem_rest,
	char **mem_buffer)
/**
* Releases allocated memories, clearing memories used in jobs in other functions
*/
{
	if (mem_line)
	{
		if (*mem_line)
			free(*mem_line);
		*mem_line = NULL;
	}
	if (mem_rest)
	{
		if (*mem_rest)
			free(*mem_rest);
		*mem_rest = NULL;
	}
	if (mem_buffer)
	{
		if (*mem_buffer)
			free(*mem_buffer);
		*mem_buffer = NULL;
	}
	return (NULL);
}

static char	*get_only_line(char **rest_content, char **buffer,
	char **line, int buffer_read)
/**
* Last part of the get_next_line function. Release the memories if necessary,
* then binds the current read line that is going to be returned,
* and stores what's left of the buffer in the static variable `rest_content`
* to have the start of the next line saved for the next function call.
*/
{
	if (buffer_read == 0)
	{
		free_work_memories(NULL, rest_content, buffer);
		if (*line && **line)
			return (*line);
		return (free_work_memories(line, NULL, NULL));
	}
	free_work_memories(NULL, rest_content, buffer);
	*rest_content = content_after_line(*line);
	*line = content_before_break_line(*line);
	return (*line);
}

static char	*content_after_line(char *content)
/**
* Everything else inside the buffer after the first \n found
* is saved in the static variable `rest`.
* This ensures that the start of the next line is not lost between
* function calls.
*/
{
	int		position;
	int		size;
	char	*content_after;

	position = line_break_position(content);
	if (position < 0)
		return (NULL);
	size = ft_strlen(content);
	content_after = malloc((size - position) * sizeof(char));
	if (content_after == NULL)
		return (NULL);
	content_after[size - position - 1] = '\0';
	ft_strlcpy(content_after, content + position + 1, size - position);
	return (content_after);
}

static char	*content_before_break_line(char *content)
/**
* clips only the beginning of the content, before the first \n
*/
{
	int		position;
	char	*content_before;

	position = line_break_position(content);
	if (!content)
		return (NULL);
	if (position < 0)
		return (content);
	content_before = malloc((position + 2) * sizeof(char));
	if (content_before == NULL)
		return (NULL);
	content_before[position + 1] = '\0';
	ft_strlcpy(content_before, content, position + 2);
	free(content);
	return (content_before);
}
