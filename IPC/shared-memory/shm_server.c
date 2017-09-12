#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    key_t my_key;
    int id_memory;
    int *memory = NULL; 	//apunta a la memoria compartida
    int i;

    // 1. Se obtiene la clave
    my_key = ftok ("clave", 10);
	printf("Mi llave es %d\n ", my_key);
    if (my_key == -1) {
        perror("No consigo clave para memoria compartida");
        return -1;
    }

	// 2. Creamos una región de memoria con la clave recién conseguida 
	id_memory =  shmget (my_key, sizeof(int)*100, 0777 | IPC_CREAT);
	if (id_memory == -1){
		perror("No consigo Id para memoria compartida");
		return -1;
	}

	//3. Ligamos la memoria creada al proceso, y obtenemos su dirección en la memoria   
	memory = (int *)shmat (id_memory, (void *)0, 0); 
	if (memory == NULL){
		perror("No consigo memoria compartida");
		return -1;
	}

	//4. Escribimos cosas en la memoria. 
	for (i=0; i<10; i++){
		memory[i]=i;        
		printf("Escrito %d\n",i);
		sleep (1);
	}

	//5. Terminada de usar la memoria compartida, la liberamos.
	shmdt ((void *)memory); // se desliga
	shmctl (id_memory, IPC_RMID, NULL); //se elimina
}
