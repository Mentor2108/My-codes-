#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 1024
#define PORT 8080

void send_file(FILE *fp, int sockfd){
  int n;
  char data[SIZE] = {0};

  while(fgets(data, SIZE, fp) != NULL) {
    if (send(sockfd, data, sizeof(data), 0) == -1) {
      perror("[-]Error in sending file.");
      exit(1);
    }
    bzero(data, SIZE);
  }
}

int main(int argc, char *argv[]){
  int e;

  if(argc!=2){
     printf("\nInvalid Server Address\n");
     exit(0);
  }
  int sockfd;
  struct sockaddr_in server_addr;
  FILE *fp;
  char *filename = "send.txt";

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("[-]Error in socket");
    exit(1);
  }
  printf("[+]Server socket created successfully.\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = 8080;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("[-]Error in socket");
    exit(1);
  }
	printf("[+]Connected to Server.\n");

  fp = fopen("sending.txt", "r");
  if (fp == NULL) {
    perror("[-]Error in reading file.");
    exit(1);
  }

  send_file(fp, sockfd);
  printf("[+]File data sent successfully.\n");

	printf("[+]Closing the connection.\n");
  close(sockfd);

  return 0;
}
