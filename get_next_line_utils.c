/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:14:57 by evportel          #+#    #+#             */
/*   Updated: 2023/06/10 01:53:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
/**
 * Retorna o tamanho de uma string válida
*/
{
	unsigned long int	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(const char *str)
/**
 * Duplica uma string em outra. aloca memória usando malloc.
*/
{
	char			*new_str;
	unsigned int	lenght;
	unsigned int	index;

	lenght = ft_strlen(str);
	new_str = malloc((lenght + 1) * sizeof(const char));
	if (new_str == NULL)
		return (NULL);
	new_str[lenght] = '\0';
	index = 0;
	while (index < lenght)
	{
		new_str[index] = str[index];
		index++;
	}
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
/**
  * concatena duas strings de comprimento fixo em uma.
  * aloca memória usando malloc.
*/
{
	char	*new_str;
	size_t	count;
	size_t	lenght_s1;
	size_t	lenght_s2;

	lenght_s1 = ft_strlen(s1);
	lenght_s2 = ft_strlen(s2);
	new_str = (char *)malloc((lenght_s1 + lenght_s2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	count = 0;
	while (count < lenght_s1)
	{
		new_str[count] = s1[count];
		count++;
	}
	count = 0;
	while (count < lenght_s2)
	{
		new_str[count + lenght_s1] = s2[count];
		count++;
	}
	new_str[count + lenght_s1] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
/**
  * copia (até tamanho bytes) o conteúdo de uma string (src) em outra (dst).
  * substitui o conteúdo de dst.
*/
{
	size_t	count;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	count = 0;
	while (count < (size - 1) && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (ft_strlen(src));
}
