#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char buffer[1024] = {0};
	char *reply = "Salut";
	int valread;	
	
	// This will create the server
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);	
	
	// The definition of the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9004);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	int addrlen = sizeof(server_address);

	// Binding socket
	bind(server_socket, (struct sockaddr*) &server_address, 
sizeof(server_address));

	listen(server_socket, 3);

int client_socket = accept(server_socket, (struct sockaddr*)&server_address, 
(socklen_t*)&addrlen);

	valread = read(client_socket, buffer, 1024);
	
	printf("%s\n",buffer);

	// Sends the message to client
	send(client_socket, reply, strlen(reply),0);

	return 0;

}
