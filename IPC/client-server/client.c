/*
	Cliente
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SIZE 255

int main(int argc, char *argv[])
{
	int my_socket, size, numbytes;
	char buffer[SIZE];

	if( argc != 3 ){
		fprintf(stderr, "error: modo de empleo: client ip puerto\n" );
		_exit( -1 );
	}

	// Se llena la estructura con los datos del servidor
	struct sockaddr_in my_structure;
	my_structure.sin_family = AF_INET;
	my_structure.sin_port = htons( atoi( argv[2] ) );
	inet_aton( argv[1], &(my_structure.sin_addr) );
	memset( &(my_structure.sin_zero), ' ', 8 );
	size = sizeof( struct sockaddr ); 

	// crear socket
	my_socket = socket( AF_INET, SOCK_STREAM, 0);
	
	// Se conecta al servidor
	connect( my_socket, (struct sockaddr *)&my_structure, size );
	
	//envia y recibe mensajes
	numbytes = recv( my_socket, buffer, SIZE-1, 0 );
	buffer[numbytes] = '\0';
	printf("%d bytes recibidos\n", numbytes );
	printf("recibido: %s\n", buffer );
	close( my_socket );
	return 0;
}
