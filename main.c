#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 15

int main() {
    int fd;                   // Descritor de arquivo
    char buffer[BUFFER_SIZE]; // Buffer para armazenar os dados lidos
    ssize_t bytes_read;       // Número de bytes lidos

    // Abrir o arquivo para leitura
    fd = open("exemplo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Ler os dados do arquivo
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo");
        close(fd);
        return 1;
    }

    // Adicionar o caractere nulo de término da string
    buffer[bytes_read] = '\0';

    // Exibir os dados lidos na tela
    printf("Bytes Read:\n%ld\n", bytes_read);
    printf("Conteúdo do arquivo:\n%s\n", buffer);

    // Fechar o arquivo
    close(fd);

    return 0;
}
