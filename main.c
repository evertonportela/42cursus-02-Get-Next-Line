#include <fcntl.h>				/* cntl = controle de arquivos = file control */
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;					/* Valores de 3 a 256 -> Valores de FD abertos, então utilizar inteiros */
	char	*line;

	/* chamando a função open, para abrir o arquivo */
	fd = open("exemplo.txt", O_RDONLY);

	/* Enquando não chega ao final do arquivo ou não há erros, chama a função gnl() */
	while (1)
	{
		/* chama a funçao gnl() e retona uma única linha, se for lido mais coisa, 
		armazena o excedente na variavel estatica*/
		line = get_next_line(fd);

		/* Se o retorno da gnl() for nulo, porque retorna nulo? */
		if (line == NULL)
		{
			printf("\nError or EOF: função retornando NULL");
			return (1);
		}
		/* Se retorna a linha, e */
		else
		{
			/* printa no terminal */
			printf("%s", line);

			/* desaloca a memoria que foi alocada dinamicamente para a linha anterior
			para receber a alocaçao da proxima linha */
			free(line);
		}
	}

	/* %d porque o FD é um inteiro, printa na tela o fd*/
	printf("%d\n", fd);
	return (0);
}