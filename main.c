#include <fcntl.h>				/* cntl = controle de arquivos = file control */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;					/* Valores de 3 a 256 -> Valores de FD abertos, então utilizar inteiros */
	char	*line;

	/* chamando a função open, para abrir o arquivo */
	fd = open("exemplo.txt", O_RDONLY);
	/* chama a funçao gnl() e retona uma única linha, se for lido mais coisa, 
	armazena o excedente na variavel estatica*/
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
/* ************************************************************************** */
	// while (line != NULL)
	// {
	// 	/* printa no terminal */
	// 	printf("%s", line);

	// 	/* desaloca a memoria que foi alocada dinamicamente para a linha anterior
	// 	para receber a alocaçao da proxima linha */
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
/* ************************************************************************** */

//	printf("ID do fd -> %d\n", fd);
	close(fd);
	return (0);
}
