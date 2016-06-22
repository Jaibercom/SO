#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main()
{
/*
   clock_t start = clock();
   printf("Start: %d\n", start);
   //... do work here
   sleep(5);
   clock_t end = clock();
   printf("end: %d\n", end);
   double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Time: %d", time_elapsed_in_seconds);
  */ 
	struct timeval t0, t1;
  
	gettimeofday(&t0, 0);
	/* ... */
	sleep(2);
	gettimeofday(&t1, 0);
	long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;	
	printf("Time: %d", elapsed);
	
	  
	return 0;
}


