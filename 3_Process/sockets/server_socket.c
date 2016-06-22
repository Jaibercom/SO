/* Estos son los ficheros de cabecera usuales */
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>        
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 3550 /* El puerto que será abierto */
#define BACKLOG 2 /* El número de conexiones permitidas */

main()
{
	/* los ficheros descriptores */
   int fd, fd2; 
	
	/* para la información de la dirección del servidor */
   struct sockaddr_in server; 
   
	/* para la información de la dirección del cliente */
   struct sockaddr_in client; 

   int sin_size;

   /* A continuación la llamada a socket() */
   if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1 ) {  
      printf("error en socket()\n");
      exit(-1);
   }

   server.sin_family = AF_INET; 
        
	/* ¿Recuerdas a htons() de la sección "Conversiones"? =) */
   server.sin_port = htons(PORT); 
   
	/* INADDR_ANY coloca nuestra dirección IP automáticamente */
   server.sin_addr.s_addr = INADDR_ANY; 
   
	
	/* escribimos ceros en  la estructura */
   bzero(&(server.sin_zero),8); 
	//memset(&(server.sin_zero),'\0', 8);
   

   /* A continuación la llamada a bind() */
   if(bind(fd,(struct sockaddr*)&server,
           sizeof(struct sockaddr))==-1) {
      printf("error en bind():  %s\n", strerror(errno));
      //printf("Oh dear, something went wrong with read()! %s\n", strerror(errno));
      exit(-1);
   }     

   if(listen(fd,BACKLOG) == -1) {  /* llamada a listen() */
      printf("error en listen()\n");
      exit(-1);
   }

   while(1) {
      sin_size=sizeof(struct sockaddr_in);
      /* A continuación la llamada a accept() */
      if ((fd2 = accept(fd,(struct sockaddr *)&client,
                        &sin_size))==-1) {
         printf("error en accept()\n");
         exit(-1);
      }
		
		/* que mostrará la IP del cliente */
      printf("Se obtuvo una conexión desde %s\n",
             "127.0.0.1" ); 
      
		/* que enviará el mensaje de bienvenida al cliente */
      send(fd2,"Bienvenido a mi servidor.\n",25,0); 
      

      close(fd2); /* cierra fd2 */
   }
}

