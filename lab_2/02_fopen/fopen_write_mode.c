#include <stdio.h>
#define FILE_PATH "data.txt"

int main(void) {

    /*
     * in the "w" mode the file don't have to be existed
     * if the file you try you to write doesn't exist yet
     * in writing mode, it will just create the file you trying to write
     *
     */
    FILE *file = fopen(FILE_PATH, "w");


    if (file == NULL) {
        printf("can not open %s\n" , FILE_PATH);
    }

    char sentence[] = "this is an example in the writing mode ";

    fwrite(sentence, sizeof(sentence), 1, file);

    fclose(file);

    return 0;
}
