#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

#define NUMTHREADS 5

sem_t rw_mutex;
sem_t mutex;
sem_t signal;

int read_count = 0;
char chdata[100] ="abc...";

void *reader(void *arg);
 void *writer(void *arg);

int main(){
	int cnt;
	pthread_t rtid[NUMTHREADS], wtid;
	int value[NUMTHREADS];
	
	sem_init(&mutex,0,1);
	sem_init(&rw_mutex,0,1);
	sem_init(&signal,0,0);

	
	for(cnt=0; cnt<NUMTHREADS; cnt++){
		value[cnt] = cnt+1; 
		pthread_create(&rtid[cnt],NULL,&reader,(void *)&value[cnt]);
	}
		
	pthread_create(&wtid, NULL, &writer, NULL);
	pthread_join(wtid,NULL);
	
	for(cnt=0; cnt<NUMTHREADS; cnt++){
		pthread_join(rtid[cnt],NULL);
	}
	
	sem_destroy(&mutex);
	sem_destroy(&rw_mutex);

	return 0;
}

void *reader(void *arg)
{
	int numThread = *(int *)arg ;
	sleep(1);
	do{
		//printf("Reader%d is waiting...\n",numThread);
		sem_wait(&mutex);
		read_count++;
		if(read_count == 1)
			sem_wait(&rw_mutex);
		
		sem_post(&mutex);
		
		//Reading

			printf("Reader%d read:  %s\n",numThread, chdata);
			

		sem_wait(&mutex);
		read_count--;
		//printf("\n\nread_count is : %d ",read_count);
		if(read_count == 0){
			sem_post(&rw_mutex);
			//printf("\nread_count is : %d \n",read_count);
		}
		sem_post(&mutex);
		sleep(1);
	}while(1);
	pthread_exit(NULL);
}

 void *writer(void *arg)
{	
	do{
		sem_wait(&rw_mutex);
		printf("\nWrite data: ");
		setbuf(stdin, NULL);
		scanf("%s",chdata);
		
		sem_post(&rw_mutex);
		sleep(1);
	}while(1);
	pthread_exit(NULL);
}
