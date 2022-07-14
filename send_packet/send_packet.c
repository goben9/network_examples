// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT	 8080
#define SERVER   "127.0.0.1"
#define MAXLINE 1024
	
// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from client, this is another test";
	struct sockaddr_in	 servaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);

	if (inet_aton(SERVER , &servaddr.sin_addr) == 0) {
        fprintf(stderr, "inet_aton() failed\n");
        exit(EXIT_FAILURE);
    }
		
	sendto(sockfd, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));
	printf("Hello message sent.\n");
	
	close(sockfd);
	return 0;
}
