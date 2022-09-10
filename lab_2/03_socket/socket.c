#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>     // socket() PF_INET SOCK_STREAM SOCK_DGRAM
#include <fcntl.h>
#include <unistd.h>         // close()


int main (void) {

    int fd1, fd2, fd3;

    fd1 = socket(PF_INET, SOCK_STREAM, 0);

    fd2 = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);


    printf("file descriptor fd1 => %d \n", fd1);
    printf("file descriptor fd2 => %d \n", fd2);
    printf("file descriptor fd3 => %d \n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}



