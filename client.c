#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address
    serverAddr.sin_port = htons(8888);                     // Server port

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int choice;
    char buffer[MAX_BUFFER_SIZE];

    while (1) {

       printf("\n\n-----------------------------------------------\n");
        printf("        ~)_`Gem-Search`_(~                    |\n\n");
        printf("-----------------------------------------------\n");
        printf("1. Search for a file                          |\n");
        printf("2. Search for a string in the filesystem      |\n");
        printf("3. Display the content of a file              |\n");
        printf("4. Exit                                       |\n\n");
        printf("-----------------------------------------------\n\n");

        printf("......Enter your choice: ");

        scanf("%d", &choice);

        send(clientSocket, &choice, sizeof(choice), 0);

        switch (choice) {
            case 1: ;
                
                int case0SubChoice = 0;
                printf("\t> 1. Enter with path\n");
                printf("\t> 2. Enter without path\n");
                scanf("%d", &case0SubChoice);

                char basePath[MAX_BUFFER_SIZE] = "";
                printf("Enter the required information: ");
                if (case0SubChoice == 2) {
                    strcat(basePath, "/home");
                }
                scanf("%s", buffer);
                strcat(basePath, buffer);
                send(clientSocket, basePath, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);
                

                printf("\n---->Server response:\n");
                printf("%s", buffer);
                printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - -\n");

                break;
            case 2:
                printf("Enter the required information: ");
                getchar();
                scanf("%[^\n]s", buffer);
                send(clientSocket, buffer, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);
                
                printf("\n---->Server response:\n");
                printf("%s", buffer);
                printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - -\n");


                if (strcmp(buffer, "") == 0) {
                    printf("Error: This string was not found in any file\n");
                }
               
                else{
                 
                    int case2SubChoice = 0;
                    printf("\t>1. View a file\n");
                    printf("\t>2. Do not view file\n");
                    printf(".........Enter any Choice: ");
                    scanf("%d", &case2SubChoice);
                    getchar();
                    if (case2SubChoice == 1) {
                        printf("    Enter the path: ");
                        scanf("%[^\n]s", buffer);
                        send(clientSocket, buffer, sizeof(buffer), 0);
                        recv(clientSocket, buffer, sizeof(buffer), 0);
                        
                        printf("\n---->Server response:\n");
                        printf("%s", buffer);
                        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - -\n");

                    }
                }
                break;
            case 3:
                printf("Enter the required information: ");
                getchar();
                scanf("%[^\n]s", buffer);
                send(clientSocket, buffer, sizeof(buffer), 0);
                recv(clientSocket, buffer, sizeof(buffer), 0);

                printf("\n---->Server response:\n");
                printf("%s", buffer);
                printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - -\n");

                break;
            case 4:
                printf("\n\n-Exiing the program-\n\n\n");
                close(clientSocket);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

