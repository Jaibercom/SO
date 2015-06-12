#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t synch;

void *s1(void *arg);
void *s2(void *arg);
void *s3(void *arg);

int main(){
	int a=0,cnt,b;
	pthread_t h1_id,h2_id,h3_id;
	
	sem_init(&synch,0,0);

	pthread_create(&h1_id,NULL,&s1,NULL);
	pthread_create(&h2_id,NULL,&s2,NULL);
	pthread_create(&h3_id,NULL,&s3,NULL);
	
	pthread_join(h1_id,NULL);
	pthread_join(h2_id,NULL);
	pthread_join(h3_id,NULL);
	
	sem_destroy(&synch);

	printf("\nDone !!\n");
	return 0;
}

void *s1(void *arg){
	
	printf("\nExecuting S1..\n");
	sem_post(&synch);
	return 0;
}

void *s2(void *arg){
	
	sem_wait(&synch);
	printf("\nExecuting S2..\n");
	return 0;
}

void *s3(void *arg){
	
	//sem_wait(&synch);
	printf("\nExecuting S3..\n");
	return 0;
}

