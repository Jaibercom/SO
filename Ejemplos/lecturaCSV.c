/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
	
	//char str[] = "3.0;4.2;5.0;2.5";
	char str[200];
	char * pch;
	float value;	
	char *filename;
	FILE *file;
	//printf ("Splitting string \"%s\" into tokens:\n",str);

	if(argc != 2){
		printf ("Error en los parametros, debe ejecutarse asi: %s notas.csv\n", argv[0]);	
		return -1;
	}
	filename = argv[1];
	file = fopen(filename, "r");
	
	if(file == NULL){
		printf ("No pudo abrirse el fichero %s \n", filename);	
		return -1;
	}

	//Ya esta abierto el fichero
	fgets(str, 200, file);
	puts(str);
	
	fgets(str, 200, file);		
	puts(str);
	
	pch = strtok (str,";");
	while (pch != NULL)
	{
		printf ("String value: %s\n",pch);
		value = atof(pch);
		value++;			//Verificar que puedo operar con el numero 
		printf ("Float value %.1f\n",value);
		pch = strtok (NULL, ";");
	}
	fclose(file);
	return 0;
}
