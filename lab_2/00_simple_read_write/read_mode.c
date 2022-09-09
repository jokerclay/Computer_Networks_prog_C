#include <stdio.h>

#define FILE_PATH "data.txt"

int main(void) 
{


    FILE *file = fopen(FILE_PATH, "r");

    if (file == NULL) {
        printf("can not open %s\n" , FILE_PATH);
    }
    
    fclose(file);





    return 0;
}
