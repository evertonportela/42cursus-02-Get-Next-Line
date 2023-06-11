/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:27:50 by evportel          #+#    #+#             */
/*   Updated: 2023/06/11 13:47:10 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
/**
  * Lê de um descritor de arquivo e retorna uma linha lida por chamada,
  * incluindo \n, a menos que EOF (encontre o fim do arquivo)
  * e nenhum \n está presente, 
  * nesse caso tudo o que foi lido é retornado imediatamente.
*/
{
	static char	*rest_content;
	char		*line;
	char		*buffer;
	int			buffer_read;

/** 
 * Por ser uma variavel estática, conseguimos manipular seu valor 
 * entre várias chamadas de função 
*/
	if (!rest_content)
		rest_content = ft_strdup("");
/**
 * Nossa linha atual para trabalho será line, 
 * ela recebe todo o resto de conteúdo do arquivo.
 * nela trabalhamos a separação do que será retornado, 
 * e voltamos a guardar o restante em rest_content
*/
	line = ft_strdup(rest_content);
/**
 * buffer é responsável por receber o conteúdo lido do arquivo,
 * dependendo sempre do tamanho do BUFFER_SIZE informado na compilação
 * (+1) para inserir o \0 ao final da leitura do buffer.
*/
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
/**
 * como de praxe, se o malloc falhar, encerramos a função
*/
	if (buffer == NULL)
		return (NULL);
/** 
 * Aqui é uma inicialização de variável, 
 * essa flag de quanto conteúdo foi lido, será util depois
*/
	buffer_read = BUFFER_SIZE;
/**
 * Enquanto buffer lido for igual a BUFFER_SIZE
 * (o que significa que estou gastando todo buffer
 * e mesmo assim não li todo o conteúdo)
 * e também não houver quebras de linha
*/
	while (buffer_read == BUFFER_SIZE && (line_break_position(line) <= 0))
	/* ************************ ponto de atenção nessa comparação ***** */

	{
	/**
	 * Fazemos a leitura do arquivo, colocando o conteúdo em buffer
	*/
		buffer_read = read(fd, buffer, BUFFER_SIZE);
	/**
	 * Se a leitura do arquivo é negativo, então chegamos ao final do arquivo
	 * Assim, liberamos as memórias que foram alocadas durante os trabalhos
	 * a linha, o resto do conteudo e o buffer de leitura
	*/
		if (buffer_read < 0)
			return (free_work_memories(&line, &rest_content, &buffer));
	/**
	 * Concatena o conteúdo lido de cada buffer a cada novo loop do enquanto
	 * adicionando o conteúdo em line, 
	 * para trabalharmos os filtros num outro momento
	*/
		return (get_only_line(&rest_content, &buffer, &line, &buffer_read));
	}
}

static void *free_work_memories(char **mem_line, char **mem_rest, char **mem_buffer)
{
/**
 * Libera as memórias alocadas, 
 * limpando as memórias usadas em trabalhos nas outras funções
*/
	/** se o parametro da linha é válido */
	if (mem_line)
	{
		/** se o ponteiro que aponta para a linha é válido 
		 * libera a memória
		 * e obrigatóriamente marca o ponteiro como nulo
		*/
		if (*mem_line)
			free(*mem_line);
		*mem_line = NULL;
	}
	/** se o parametro de resto de conteúdo é válido */
	if (mem_rest)
	{
		/** se o ponteiro que aponta para o resto do conteúdo é válido 
		 * libera a memória
		 * e obrigatóriamente marca o ponteiro como nulo
		*/
		if (*mem_rest)
			free(*mem_rest);
		*mem_rest = NULL;
	}
	/** se o parametro de buffer é válido */
	if (mem_buffer)
	{
		/** se o ponteiro que aponta para buffer é válido 
		 * libera a memória
		 * e obrigatóriamente marca o ponteiro como nulo
		*/
		if (*mem_buffer)
			free(*mem_buffer);
		*mem_buffer = NULL;
	}
	/** se não entrar em nenhuma condição, retorna NULL*/
	return (NULL);
}

static char	*get_only_line(char **rest_content, char **buffer,
	char **line, char **buffer_read)
/**
 * Ultima parte da função get_next_line. Libera as memórias se necessário,
 * em seguida, vincula a linha de leitura atual que vai ser retornada,
 * e armazena o que sobrou do buffer na variável estática `rest_content`
 * para ter o início da próxima linha salvo para a próxima chamada de função.
*/
{
/**
 * Verifica se o buffer_read é zero, 
 * num caso de fim de arquivo, libera as memórias usadas
*/
	if (buffer_read == 0)
	{
		free_work_memories(NULL, rest_content, buffer);
		/** Se o parametro é um ponteiro válido e 
		 * o ponteiro que aponta para a linha também é válido, ou seja, 
		 * o primeiro caractere da linha) */
		if (*line && **line)
			return (*line);
		/** se as linhas não forem válidas, libera a memória da linha */
		return (free_work_memories(line, NULL, NULL));
	}
	/** se o buffer de leitura é positivo, ou seja, 
	 * leu algum conteúdo com sucesso, libera a memória do resto do conteúdo 
	 * e do buffer de leitura, mas não da linha atual. */
	free_work_memories(NULL, rest_content, buffer);
	/** salva o conteúdo restante do arquivo, 
	 * desconsiderando a linha atual, que será retornada. 
	 * Ou seja, só pega conteúdo depois da quebra de linha */
	*rest_content = content_after_line(*line);
	/** salva o conteúdo do início do arquivo,
	 * antes do primeiro \n, considerando apenas conteúdo que será retornado */
	*line = content_before_break_line(*line);
	/** e retornamos apenas esse primeiro pedaço de conteúdo */
	return (*line);
}

static char	*content_after_line(char *content)
/**
  * Todo o resto dentro do buffer após o primeiro \n encontrado
  * é salvo na variável estática `rest`. 
  * Isso garante que o início da próxima linha não se perca entre
  * chamadas de função.
*/
{
	int		position;
	int		size;
	char	*content_after;

	/** já temos uma funçao que busca o \n
	 * vamos aproveita-la para achar a posiçao da quebra de linha
	*/
	position = line_break_position(content);
	/** Se a posição retornada for menor ou igual a zero, 
	 * significa que a linha está vazia então retorna null*/
	if (position <= 0)
		return (NULL);
	/* ************************ ponto de atenção nessa comparação ***** */
	/** vamos alocar uma memória para receber todo o conteudo após o \n */
	size = ft_strlen(content) - position;
	content_after = malloc(size * sizeof(char));
	/** de praxe, se o malloc falhar, retorna null */
	if (content_after == NULL)
		return (NULL);
	content_after[size - 1] = '\0';
	ft_strlcpy(content_after, content + position + 1, size - position);
	/* **** ponto de atenção na conta do terceiro parametro ******** */
	return (content_after);
}

static char	*content_before_break_line(char *content)
/**
 * recorta apenas o início do conteúdo, antes do primeiro \n
*/
{
	int		position;
	char	*content_before;

	/** já temos uma funçao que busca o \n
	 * vamos aproveita-la para achar a posiçao da quebra de linha
	*/
	position = line_break_position(content);
	/** se o conteúdo é nulo, encerra a função e retorna nulo */
	if (!content)
		return (NULL);
	/** Se a posição retornada for menor ou igual a zero, 
	 * significa que a linha contém quebra, e retorna o conteúdo inteiro */
	if (position <= 0)
		return (content);
	/* ************************ ponto de atenção nessa comparação ***** */
	/** vamos alocar uma memória para receber todo o conteudo antes do \n 
	 * e um espaço para o próprio \n + mais espaço para o \0	*/
	content_before = malloc((position + 2) + sizeof(char));
	/** de praxe, se o malloc falhar, retorna null */
	if (content_before == NULL)
		return (NULL);
	/** essa atribuição é realmente necessária? se o strlpcy tbm coloca \0 ao final
	 * vale testar todas as 
	 */
	content_before[position + 1] = '\0';
	ft_strlcpy(content_before, content, position + 2);
}
