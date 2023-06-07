/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:39:48 by evportel          #+#    #+#             */
/*   Updated: 2023/06/06 20:59:58 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
/* **************************************************************************
** ************************************************************************** */
	static char	*accumulator;
	char		*buffer;
	char		*current_line;

/* **************************************************************************
	Verifica se o arquivo para leitura contém erro ao abrir
	E retorna nulo nesse caso, encerrando a função neste ponto
** ************************************************************************** */
	if (read(fd, 0, 0) == -1)
		return (NULL);

/* **************************************************************************
	Aloca memória para conteúdo a ser lido, conforme o tamanho do buffer
	informado na compilação
** ************************************************************************** */
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));

/* **************************************************************************
	Se a alocação de memória falhar, encerra a função retornando nulo
** ************************************************************************** */
	if (!buffer)
		return (NULL);

/* **************************************************************************

** ************************************************************************** */
	current_line = NULL;
	accumulator = get_comp(fd, buffer, accumulator, current_line);
	free(buffer);
	current_line = ft_strnldup(accumulator);
	accumulator = verif(accumulator);
	return (current_line);
}
