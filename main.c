// main.c

#include "server.h"

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind to a specific port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8888...\n");
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == -1) {
        perror("Accept failed");
    }

    // Accept connections
    while (1) {
        // Receive client choice
        int choice;
        recv(clientSocket, &choice, sizeof(choice), 0);
        printf("Choice: %d\n", choice);

        char buffer[MAX_BUFFER_SIZE] = "";
        char result[MAX_BUFFER_SIZE] = "";

        switch (choice) {
            case 1:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForFile(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 2:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                searchForString(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                strcpy(result, "");
                recv(clientSocket, buffer, sizeof(buffer), 0);
                displayFileContent(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 3:
                recv(clientSocket, buffer, sizeof(buffer), 0);
                displayFileContent(buffer, result);
                send(clientSocket, result, sizeof(result), 0);
                break;

            case 4:
                close(clientSocket);
                close(serverSocket);
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice from client.\n");
        }
    }

    close(clientSocket);
    return 0;
}
