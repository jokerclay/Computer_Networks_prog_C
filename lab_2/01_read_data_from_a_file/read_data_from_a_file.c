#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>      // O_RDONLY ....

#define BUFFER_SIZE 225

int main(void) {

    int fd;
    const char *buffer[BUFFER_SIZE];

    fd = open("data.txt", O_RDONLY);

    if (fd == -1) {
        printf("ERROR: can not open data.txt\n");
    }

    printf("file discriptor is => %d \n", fd);

    /*
     *
     * read function call
     *
     */

    if (read(fd, &buffer, sizeof(buffer)) == -1) {
        printf("ERROR: can not read from data.txt\n");
    };

    printf("file data in data.txt => \n%s  ", buffer);

    close(fd);

    return 0;
}
