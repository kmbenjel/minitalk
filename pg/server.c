#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int sockfd;
int BUFFER_SIZE = 256;

void error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
    exit(1);
}

void handle_client() {
    int newsockfd, clilen, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in cli_addr;

    clilen = sizeof(cli_addr);

    // Accept connection
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    // Receive message from client
    memset(buffer, 0, BUFFER_SIZE);
    n = read(newsockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0)
        error("ERROR reading from socket");

    // Print received message
    write(STDOUT_FILENO, "Received message: ", strlen("Received message: "));
    write(STDOUT_FILENO, buffer, strlen(buffer));
    write(STDOUT_FILENO, "\n", 1);

    // Close socket
    close(newsockfd);
}

int main() {
    int portno;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Clear address structure
    memset((char *)&serv_addr, 0, sizeof(serv_addr));

    // Port number
    portno = 12345;

    // Set up the server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen for connections
    listen(sockfd, 5);
    char pid_buffer[32]; // Increased buffer size
    int pid = getpid();
    sprintf(pid_buffer, "Server started. PID: %d\n", pid);
    write(STDOUT_FILENO, pid_buffer, strlen(pid_buffer));

    // Handle clients
    while (1) {
        handle_client();
    }

    // Close socket
    close(sockfd);

    return 0;
}

