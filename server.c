#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main()
{
	char server_message[256] = "salut du serveur";
	
	// This will create the server
	int server_socket = socket(AF_INET, SOCK_STREAM, 0)	
	
	// The definition of the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// Binding socket
	bind(server_socket, (struct sockaddr*) &server_address, 
sizeof(server_address));

	listen(server_socket, 3);

	int client_socket = accept(server_socket, NULL, NULL);
	// Sends the message to client
	send(client_socket, server_message, sizeof(server_message), 0);
	
	// Closes the socket
	close(server_socket);	

	return 0;

}
