/*
	Ejemplo para lectura de un archivo usando la función getline
	
	Mayor información:
	http://man7.org/linux/man-pages/man3/getline.3.html

*/


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   FILE *file;
   char *line = NULL;
   size_t len = 0;
   ssize_t nread;

   if (argc != 2) {
       fprintf(stderr, "Usage: %s <file>\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   file = fopen(argv[1], "r");
   if (file == NULL) {
       perror("fopen");
       exit(EXIT_FAILURE);
   }

   while ((nread = getline(&line, &len, file)) != -1) {
       	printf("Retrieved line of length %zu:\n", nread);
		printf("%s", line);
   }

   free(line);
   fclose(file);
   exit(EXIT_SUCCESS);
}
