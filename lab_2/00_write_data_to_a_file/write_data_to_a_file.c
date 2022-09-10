#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>      // O_RDONLY ....

int main(void) {

    int fd;
    /*
     *--------------------------------
     *| fd   |                       |
     *--------------------------------
     *| 0    |stardand input         |
     *--------------------------------
     *| 1    |stardand output        |
     *--------------------------------
     *| 2    |stardand error         |
     *--------------------------------
     * */


    char buffer[] = "this is the data of this file.\n";


    fd = open("data.txt", O_RDONLY | O_WRONLY | O_TRUNC);



    if (fd == -1) {
        printf("ERROR: can not open data.txt\n");
    }

    printf("file discriptor is : %d \n", fd);

    /*
     *
     * write function call
     *
     */


    if (write(fd, &buffer, sizeof(buffer)) == -1) {

        printf("ERROR: can not write buffer to  data.txt\n");

    };


    close(fd);

    return 0;
}



