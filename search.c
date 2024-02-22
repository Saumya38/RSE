// search.c

#include "server.h"

void searchForFile(char* filePath, char* result) {
    FILE* file = fopen(filePath, "r");
    if (file != NULL) {
        fclose(file);
        strcat(result, "Yes, the file exists!");
    } else {
        strcat(result, "No, the file does not exist!");
    }
}
