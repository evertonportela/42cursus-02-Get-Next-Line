/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:53:01 by evportel          #+#    #+#             */
/*   Updated: 2023/06/08 12:06:31 by evportel         ###   ########.fr       */
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
/* ************************************************************************** */
/* Variáveis utilizadas pela função                                           */
/* *buffer -> um ponteiro para o pedaço de conteúdo lido no arquivo.          */
/* Por que pedaço?                                                            */
/* Porque o tamanho é definido pelo BUFFER_SIZE na hora da compilação         */
/* buffer_read -> recebe um valor númerico, referente a quantos bites a       */
/* função read() conseguiu ler.                                               */
/* Por isso ela é do mesmo tipo retornado pela função.                        */
/* ************************************************************************** */
	char	*buffer;
	ssize_t	buffer_read;

/* ************************************************************************** */
/* O quanto de conteúdo que vai ser lido, depende do BUFFER_SIZE, então       */
/* alocamos o suficiente para uma leitura,                                    */
/* aproveitando o que foi informado na compilação                             */
/* ************************************************************************** */
	buffer = (char *) malloc(BUFFER_SIZE + 1);

/* ************************************************************************** */
/* E se por acaso o malloc falhar? Encerramos a função e retornamos nulo. */
/* ************************************************************************** */
	if (buffer == NULL)
		return (NULL);

/* ************************************************************************** */
/* read() lê o conteúdo do arquivo,  */
/* e retorna a quantidade de bites que foram lidos. detalhe aqui é que */
/* pode ser uma quatidade menor que o informado no BUFFER_SIZE */
/* ************************************************************************** */
	buffer_read = read(fd, buffer, BUFFER_SIZE);
// read retornando 0, significa fim do arquivo

/* ************************************************************************** */
/* Se falhar na leitura do arquivo, (o retorno é -1) */
/* Encerra a função, por segurança libera a memória alocada e retorna nulo. */
/* ************************************************************************** */
	if (buffer_read <= 0)
	{
		free(buffer);
		return (NULL);
	}

/* ************************************************************************** */
/* Adiciona caractere nulo ao fim da leitura para retornar uma string válida */
/* ************************************************************************** */
	buffer[buffer_read] = '\0';

/* ************************************************************************** */
/* Retorna o buffer lido */
/* ************************************************************************** */
	return (buffer);
}
