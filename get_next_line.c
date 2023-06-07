/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:53:01 by evportel          #+#    #+#             */
/*   Updated: 2023/06/07 19:55:37 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	c = (unsigned char)c;
	if (s[index] == 0)
		return ((char *)s);
	while (s[index])
	{
		if (s[index] == c)
		{
			return ((char *)s + index);
		}
		else if (s[index + 1] == c)
		{
			return ((char *)s + (index + 1));
		}
		index++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	buffer_read;

// malloc o tamanho do buffer, suficiente ao buffer_size
	buffer = (char *) malloc(BUFFER_SIZE);
// malloc falhou, encerra a função e retorna nulo
	if (buffer == NULL)
		return (NULL);
// lê o conteúdo do arquivo
	buffer_read = read(fd, buffer, BUFFER_SIZE);
// se falhar na leitura do arquivo, encerra a função e retorna nulo
	if (buffer_read <= 0)
		return (NULL);
// adiciona caractere nulo ao fim da leitura para retornar uma string válida
// retorna o buffer lido
	return (buffer);
}
