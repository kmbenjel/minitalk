#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int sockfd;
int BUFFER_SIZE = 256;

void error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    exit(1);
}

void send_message(const char *hostname, int portno, const char *message) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Get server host by name
    server = gethostbyname(hostname);
    if (server == NULL) {
        write(STDERR_FILENO, "ERROR, no such host\n", strlen("ERROR, no such host\n"));
        exit(1);
    }

    // Clear address structure
    memset((char *)&serv_addr, 0, sizeof(serv_addr));

    // Set up the server address structure
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Send message to server
    int n = write(sockfd, message, strlen(message));
    if (n < 0)
        error("ERROR writing to socket");

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <message>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *message = argv[2];
    int portno = 12345;

    send_message(hostname, portno, message);

    return 0;
}

