/*
	Consumer program illustrating POXIS shared-memory API 
	to execute : gcc consumer.c -o consumer -lrt
 

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096;

	/* name of the shared memory object */
	const char *name = "OS";

	/* shared memory file descriptor */
	int shmfd;

	/* pointer to shared memory object */
	void *ptr;

	/* open the shared memory object */
	shmfd = shm_open(name, O_RDONLY, 0666);

	/* memory map the shared memory object */
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shmfd, 0);
	
	/* read from the shared memory object */
	printf("\n%s\n",(char *)ptr);
	
	/* remove the shared memory object */
	shm_unlink(name);
	return 0;
}