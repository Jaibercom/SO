/*
	Servidor
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main( int argc, char *argv[] )
{
	int my_socket, sockfd, size;
	struct sockaddr_in  my_structure;
	int flag = 1;
	char msgWelcome[] = "200 Bienvenido\n";


	// llenar la estructura
	my_structure.sin_family = AF_INET;
	my_structure.sin_port = htons(65000);  		// de 1024 a 65535
	my_structure.sin_addr.s_addr = INADDR_ANY; 	// tomar cualquier dir local
	memset( &(my_structure.sin_zero), '0', 8 );	// arreglo de 0 para completar el tamaño de sockaddr

	char *ip = inet_ntoa( my_structure.sin_addr);
	int port= ntohs(my_structure.sin_port);
	printf("Padre: Servidor: mi ip es %s y el puerto es %d",ip, port);

	// 1. crear el sockect
	my_socket = socket( AF_INET, SOCK_STREAM, 0 );
	size= sizeof( struct sockaddr );
	
	// 2. Asociar el puerto 	
	bind( my_socket, (struct sockaddr *)&my_structure, size);
	
	// 3. escuchar peticiones 
	listen( my_socket, 5 );
	
	// 4. loop para aceptar peticiones 
	while( flag == 1 ) {  // bucle infinito para tratar conexiones
		
		struct sockaddr_in  my_client;
		printf("\n\nPadre: Esperando peticiones...");
		fflush(stdout);
		
		// 5. Aceptar peticiones
		sockfd= accept( my_socket,  (struct sockaddr *)&my_client, &size);
		
		// 6. Se crea un proceso hijo para atender cada petición
		if( fork() == 0 )
		{ // hijo
			close( my_socket ); //El proceso hijo no lo necesita ya que accept crea un socket nuevo 
			// datos del cliente 
			char *ipClient = inet_ntoa( my_client.sin_addr);
			int portClient = ntohs(my_client.sin_port);
			
			printf("\nHijo pid %d: conversando con cliente %s,  puerto %d\n", getpid(), ipClient, portClient);
			//envio y recepcion de mensajes
			send( sockfd, msgWelcome, strlen(msgWelcome), 0 );
			printf("Hijo: finalizando la comunicacion con el cliente.");
			
			close( sockfd );
			exit( 0 );
		} else { // padre
			close( sockfd );  // El proceso padre no lo necesita
			//printf("\nDigita 0 para terminar, 1 para continuar = ");
			//scanf("%d",&flag);
		}
	}
	close(my_socket);
	return 0;
}
