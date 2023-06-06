#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


char    *get_next_line(int fd)
{
    static char     *buffer;
    char            *line;
    char            *p;
    int             read_bytes;

    if (!buffer)
    {
        buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
        if (!buffer)
            return (NULL);
    }

    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if (read_bytes == -1 || read_bytes == 0)
        return (NULL);

    line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!line)
        return (NULL);

    p = line;
    while (*buffer)
        *p++ = *buffer++;
    return (line);
}

int    main(void)
{
int        fd;
     char    *line;

     fd = open("exemplo.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    return (0);
}