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
 *
 */


#include <stdio.h>
#include <stdlib.h>

int main (void)  {


    FILE *file_to_read = fopen("read_file.txt", "r");
    FILE *file_to_write = fopen("write_file.txt", "w");


    char str[] = "ONE DAY\n";
    fwrite(str, 1, sizeof(str), file_to_write);


    if (file_to_read == NULL || file_to_write == NULL) {
        printf("one file can not be open\n");
    }

    char c;

    while ((c = fgetc(file_to_read)) != EOF ) {

        if (c == ',') {
            c = '~'; 
        }

        fputc(c,file_to_write);

    }
    fclose(file_to_read);
    fclose(file_to_write);

    return 0;
}

