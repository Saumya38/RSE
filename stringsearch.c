// stringsearch.c
// home2/user28
#include "server.h"

void searchForString(const char* searchString, char* result) {
    searchInDirectory("/Users/singhshivam/Documents/project", searchString, result);
}
