#include <fcntl.h>				/* cntl = controle de arquivos = file control */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;					/* Valores de 3 a 256 -> Valores de FD abertos, então utilizar inteiros */
	char	*line;

	/* chamando a função open, para abrir o arquivo */
	fd = open("exemplo.txt", O_RDONLY);
	int contador = 5;
	/* chama a funçao gnl() e retona uma única linha, se for lido mais coisa, 
	armazena o excedente na variavel estatica*/
	line = get_next_line(fd);
	while (line != NULL)
	{
		/* printa no terminal */
		printf("%s", line);

		/* desaloca a memoria que foi alocada dinamicamente para a linha anterior
		para receber a alocaçao da proxima linha */
		free(line);
		line = get_next_line(fd);
	}
	printf("%d\n", fd);
	close(fd);
	return (0);
}
