#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888

int main() {
    int sock_fd, ret;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Send data to server
    while (1) {
        printf("Enter message to send to server (enter \"exit\" to quit):\n");
        fgets(buf, BUF_SIZE, stdin);

        if (strncmp(buf, "exit", 4) == 0) {
            break;
        }

        ret = sendto(sock_fd, buf, strlen(buf), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (ret < 0) {
            perror("sendto failed");
            break;
        }

        // Receive data from server
        memset(buf, 0, BUF_SIZE);
        socklen_t len = sizeof(server_addr);
        ret = recvfrom(sock_fd, buf, BUF_SIZE, 0, (struct sockaddr*)&server_addr, &len);
        if (ret < 0) {
            perror("recvfrom failed");
            break;
        }

        printf("Received message from server: %s\n", buf);
    }

    // Close socket
    close(sock_fd);

    return 0;
}