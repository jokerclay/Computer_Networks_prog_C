/*
 * 2 ways of reading & wrting files
 *      1. fopen()
 *           fopen("my_file.txt", "r")
 *                      |          |
 *                      V          V
 *                 file path      stream mode
 *                              ("w" "w+" "r" ...)
 *
 *          return a pointer to a FILE struct
 *          Use that pointer as a handle to access the file
 *          (means use fread(), fwrite(), fprtinf(), feof(), fclose() ect...)
 *
 *      2. open()
 *          open() is a system call and it exist on linux mac 
 *          open("my_file.txt", O_RDONLY);
 *                      |          |
 *                      V          V
 *                 file path    mode flag
 *          return a `int` which is file discriptor 
 *          file discriptor is a number operating system use it to  track 
 *          file 
 *          every file have a number called **file discriptor**
 *
 *      ------------------------------------------------------------
 *      fopen use buffering
 *      open do system call every time
 *      however, fopen wait the byte to be a chunk of bytes
 *      so, fopen have fewer system call 
 *      that's why fopen would be faster
 *      ------------------------------------------------------------
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>      // O_RDONLY ....

int main (void)  {

    int fd_to_read = open("read_file_2.txt", O_RDONLY);
    int fd_to_write = open("write_file_2.txt", O_WRONLY |
                                               O_CREAT, S_IRUSR |
                                               S_IWUSR
                                               );


    if (fd_to_read == -1 || fd_to_write == -1) {
        printf("one file can not be opened");
        return -1;
    }

    char c;
    int bytes;
    while ((bytes = read(fd_to_read, &c, sizeof(c))) > 0) {
        if (c == ',') {
            c = '~';
        }
        write(fd_to_write, &c, sizeof(c));
    }

    close(fd_to_read);
    close(fd_to_write);

    return 0;
}
































