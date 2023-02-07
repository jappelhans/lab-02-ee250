# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Jerry Appelhans
- n/a (worked individually)

## Lab Question Answers

Answer for Question 1: 
    With a 50% loss added to the UDP server, about half of the messages that the client tries to send to the server are lost.  When these messages are lost, they are completely dropped and therefore never arrive at the server.

Answer for Question 2:
    With a 50% loss added to the TCP server, the reliability is affected differently than the UDP link.  With TCP, every message that the client sends is eventually received by the server.  When a message is lost, it is retransmitted instead of just being dropped.  In this way, the reliability is much better than UDP, but the drawback is a slower speed.

Answer for Question 3:
    With the 50% loss, the speed of the TCP response is much slower.  This happens because when a message is dropped, TCP spends the extra time to retransmit the lost message before it attempts to send new messages.  The lost messages are able to be detected because TCP serializes each message unlike UDP.

--------------------------------------------------------------------------------------------------------------------------------------------------------

Answers to questions in tcp_server.c:

Answer for Question 1:
    Argc represents the number of arguments passed to the program from the environment in which it is run.  *argv[] is a pointer to the first element of an array of the arguments for the program. In this program, argv[1] is the port number that we use to open the server.

Answer for Question 2:
    A UNIX file descriptor is a positive integer value that represents an open file being used in a process.  A file descriptor table is a collection of file descriptors and the pointers to the corresponding files that each descriptor represents.

Answer for Question 3:
    A struct is a user-defined data type that allows for grouping related variables for convenience.  sockaddr_in contains the variables for the server family, address, and port of a socket.

Answer for Question 4:
    The input parameters of socket() are domain, type, and protocol. In this case, the domain parameter is AF_INET, which specifies that the socket will be able to communicate with IPv4 addresses. The type parameter specifies the type of socket to be created (SOCK_STREAM in this case).  The protocol parameter can be used to specify a specific communication protocol.  In this case, it is 0 which means the socket will use the default protocol for the given address family and socket type.
    The return value of socket() is a file descriptor that can be used later on to refer to the socket that the function creates. Because the function returns a file descriptor, we can check to see if socket() worked by making sure sockfd is positive.

Answer for Question 5:
    The input parameters of bind() are socket, address, and address_len. Socket is the file descriptor created by the socket() function earlier.  Address is a pointer to a sockaddr structure containing the name we want to bind to the socket.  Address_len is simply the size of the address parameter in bytes.
    The input parameters of listen() are socket and backlog. Socket is the file descriptor for the socket that we want to start listening on. Backlog sets the maximum allowed length for the queue of pending connections.

Answer for Question 6:
    The while loop allows the server to receive messages indefinitely.  Without the while loop, it would receive a single message then immediately close the socket and terminate the program. One issue with the while loop is that it can only process one connection at a time. If there are multiple simultaneous connections to handle, they will have to wait for the while loop to finish each one at a time.

Answer for Question 7:
    The fork() function creates a child process that runs in sync with the parent program. This could be applied here by making a child process for each new incoming connection. This would allow the server to better handle multiple simultaneous incoming connections instead of putting them in a queue.

Answer for Question 8:
    A system call is a function in a program that requests an external service from the operating system. This is necessary for networking because the program needs to make changes to things that the operating system has control of like opening sockets and sending data to other computers over the network.
