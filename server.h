// server.h

#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <limits.h>

#define MAX_BUFFER_SIZE 1024

void searchForFile(char* filePath, char* result);
void searchInFile(const char* filePath, const char* searchString, char* result);
void searchInDirectory(const char* dirPath, const char* searchString, char* result);
void searchForString(const char* searchString, char* result);
void displayFileContent(char* filePath, char* result);
int main();  

#endif
