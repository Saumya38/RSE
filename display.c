// display.c

#include "server.h"

void displayFileContent(char* filePath, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        strcat(result, "File exists, content of file:-\n");
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            strcat(result, buffer);
        }
        fclose(file);
    } else {
        strcpy(result, "File does not exist\n");
    }
}
