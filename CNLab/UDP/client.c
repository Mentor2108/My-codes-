#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t server_len;
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
    if (inet_aton(SERVER_IP, &server_addr.sin_addr) == 0)
        error("Invalid server IP address");

    printf("Enter the file name: ");
    fgets(buffer, BUF_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    // Send file name to server
    server_len = sizeof(server_addr);
    int n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, server_len);
    if (n < 0)
        error("Error sending file name");

    // Open the file for reading
    file = fopen(buffer, "rb");
    if (file == NULL)
        error("Error opening file");

    // Read and send file data
    while (!feof(file)) {
        memset(buffer, 0, BUF_SIZE);
        n = fread(buffer, 1, BUF_SIZE, file);
        if (n < 0)
            error("Error reading file");

        // Send data to server
        sendto(sockfd, buffer, n, 0, (struct sockaddr *)&server_addr, server_len);

        // Wait for acknowledgement
        memset(buffer, 0, BUF_SIZE);
        n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&server_addr, &server_len);
        if (n < 0)
            error("Error receiving acknowledgement");

        // Verify acknowledgement
        if (strncmp(buffer, "ACK", 3) != 0)
            error("Invalid acknowledgement");
    }

    // Close the file
    fclose(file);
    printf("File sent successfully.\n");

    // Close the socket
    close(sockfd);

    return 0;
}
