// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

//using namespace std;

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = argv[1];
	std::string server_port = argv[2];
	printf("server ip: %s\n", server_ip.c_str());
	printf("server port: %s\n", server_port.c_str());

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	

	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(client_fd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
	int connectRes = connect(client_fd, server_addr->ai_addr, server_addr->ai_addrlen);
	if (connectRes == -1) {
		printf("failed to connect\n");
		return 1;
	}

	// TODO: Retreive user input
	std::string userInput;
	printf("CLIENT> ");
	std::getline(std::cin, userInput);

	// TODO: Send() the user input to the server
	int sendRes = send(client_fd, userInput.c_str(), userInput.size()+1, 0);
	if (sendRes == -1)
		printf("Could not send to server");

	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	memset(socket_read_buffer, '\0', 1024);
	// Because I filled the entire socket_read_buffer with NULL characters, the string is guaranteed to be null terminated.
	int bytesReceived = recv(client_fd, socket_read_buffer, 1024, 0);
	printf("SERVER> %s\n", std::string(socket_read_buffer, bytesReceived).c_str());

	// TODO: Close() the socket
	close(client_fd);

	return 0; 
} 
