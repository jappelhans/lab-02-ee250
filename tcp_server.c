/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     *    argc represents the number of arguments passed to the program from the environment in which it is run.  *argv[] is a pointer to the first element of an array of the arguments for the program.
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     *    A UNIX file descriptor is a positive integer value that represents an open file being used in a process.  A file descriptor table is a collection of file descriptors and the pointers to the files that each descriptor represents.
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     *    A struct is a user-defined data type that allows for grouping related variables.  sockaddr_in contains the variables for the server family, address, and port.
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     *    The input parameters of socket() are domain, type, and protocol. In this case, the domain parameter is AF_INET, which specifies that the socket will be able to communicate with IPv4 addresses. The type parameter specifies the type of socket to be created (SOCK_STREAM in this case).  The protocol parameter can be used to specify a specific protocol.  In this case, it is 0 which means the socket will use the default protocol for the given address family and socket type.
     *    The return value of socket() is a file descriptor that can be used later on to refer to the socket that the function creates. Because the function returns a file descriptor, we can check to see if socket() worked by making sure sockfd is positive.
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     *    The input parameters of bind() are socket, address, and address_len. Socket is the file descriptor created by the socket() function earlier.  Address is a pointer to a sockaddr structure containing the name we want to bind to the socket.  Address_len is simply the size of the address parameter in bytes.
     *    The input parameters of listen() are socket and backlog. Socket is the file descriptor for the socket that we want to start listening on. Backlog sets the maximum allowed length for the queue of pending connections.
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *      The while loop allows the server to receive messages indefinitely.  Without the while loop, it would receive a single message then immediately close the socket and terminate the program. One issue with the while loop is that it can only process one connection at a time. If there are multiple simultaneous connections to handle, they will have to wait for the while loop to finish each one at a time.
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         *    The fork() function creates a child process that runs in sync with the parent program. This could be applied here by making a child process for each incoming connection. This would allow the server to better handle multiple simultaneous incoming connections.
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 * A system call is a function in a program that requests a service from the operating system. This is necessary for networking because the program needs to make changes to things that the operating system has control of like opening sockets and communicating with other computers.
 */
