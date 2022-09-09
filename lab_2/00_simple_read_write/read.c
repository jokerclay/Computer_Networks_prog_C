#include <stdio.h>

#define FILE_PATH "data.txt"

int main(void) 
{
    /*
     * in the "r" mode the file has to aleady existed
     * if the file you try you to read doesn't exist yet
     * you can not open file, aka "r" reading mode
     *
     */
    FILE *file = fopen(FILE_PATH, "r");

    if (file == NULL) {
        printf("can not open %s\n" , FILE_PATH);
    }

    char sentence[] = "this is an example in the reading mode ";

    fwrite(sentence, sizeof(sentence), 1, file);

    
    fclose(file);

    return 0;
}
