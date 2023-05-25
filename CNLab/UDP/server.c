#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8888

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[BUF_SIZE];
    FILE *file;

    // Create UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    // Configure server address
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error binding");

    printf("Server started and listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Receive file name from client
        memset(buffer, 0, BUF_SIZE);
        client_len = sizeof(client_addr);
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);
        if (n < 0)
            error("Error receiving file name");

        // Open the file for writing
        file = fopen(buffer, "wb");
        if (file == NULL)
            error("Error opening file");

        printf("Receiving file: %s\n", buffer);

        // Receive and write file data
        while (1) {
            memset(buffer, 0, BUF_SIZE);
            n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_len);
            if (n <= 0)
                break;

            fwrite(buffer, 1, n, file);

            // Send acknowledgement
            sendto(sockfd, "ACK", 3, 0, (struct sockaddr *)&client_addr, client_len);
        }

        // Close the file
        fclose(file);
        printf("File received successfully.\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}
