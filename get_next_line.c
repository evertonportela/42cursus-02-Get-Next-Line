/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 11:39:48 by evportel          #+#    #+#             */
/*   Updated: 2023/05/29 16:27:39 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
/* **************************************************************************
		fd                              - descritor de arquivo
 		char	buffer[BUFFER_SIZE];	- Buffer para armazenar os dados lidos
		ssize_t bytes_read;				- Número de bytes lidos
** ************************************************************************** */
	char	*buffer;
	ssize_t	bytes_read;
/* **************************************************************************
		Verifica o arquivo para leitura contém error ao abrir
		E retorna nulo nesse caso, encerrando a função neste ponto da função
** ************************************************************************** */
	if (fd == -1)
	{
		return (0);
	}
/* **************************************************************************
		Verifica a leitura do arquivo e se contém erro ao ler
		Retorna nulo, encerrando a função neste ponto da função
** ************************************************************************** */
	buffer = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		return (0);
	}
/* **************************************************************************
		Adicionar o caractere nulo de término da string
** ************************************************************************** */
	//buffer[bytes_read] = '\0';
/* **************************************************************************
		Exibir os dados lidos na tela
		Retornar os dados lidos
** ************************************************************************** */
	return (buffer);
}
