#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*gnl;

	fd = open("file_test.txt", O_RDONLY);
	gnl = get_next_line(fd);
	printf("%s", gnl);
	gnl = get_next_line(fd);
	printf("%s", gnl);


	// printf("%c", gnl[26]);

	close(fd);
	return (0);
}
/*
** clear && cc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=1 && ./a.out | cat -e
** clear && cc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=42 && ./a.out | cat -e
** clear && cc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=10000 && ./a.out | cat -e
*/
