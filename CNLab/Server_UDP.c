#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256
#define SERVER_PORT 8888

int main() {
    int sock_fd, ret;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to address
    if (bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP server listening on port %d...\n", SERVER_PORT);

    // Receive data from clients
    while (1) {
        memset(&client_addr, 0, sizeof(client_addr));
        memset(buf, 0, BUF_SIZE);

        // Receive data
        socklen_t len = sizeof(client_addr);
        ret = recvfrom(sock_fd, buf, BUF_SIZE, 0, (struct sockaddr*)&client_addr, &len);

        if (ret < 0) {
            perror("recvfrom failed");
            break;
        }

        printf("Received message from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);
        printf("Enter Message to send to the client: ");
        char temp[BUF_SIZE];
        scanf("%s", temp);
        // Echo data back to client
        ret = sendto(sock_fd, temp, strlen(temp), 0, (struct sockaddr*)&client_addr, len);
        if (ret < 0) {
            perror("sendto failed");
            break;
        }
    }

    // Close socket
    close(sock_fd);

    return 0;
}