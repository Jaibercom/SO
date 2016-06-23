/*
* tabulados.c
* Juangui Restrepo
* Un ejemplo rapido de lectura de archivos con datos tabulados
* EJERCICIO: Obtenga el numero de lineas desde el archivo.
* EJERCICIO: Organice en funciones.
* EJERCICIO: Obtenga el nombre del archivo desde la consola.
* NOTA: Hay editores que convierten las tabulaciones en espacios.
*       Esto afectara el funcionamiento de la aplicacion.
*/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int i;
    char *fileName = (char *)"tabulados.txt";
    FILE *file;
    int exitValue;
    
    file = fopen(fileName, "r");
    if(file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(8);
    } else {
        printf("El archivo fue abierto.\n\n");
    }
    
    char *token;
    char buffer[10];
    for(i = 0; i < 2; i++) {
        fgets(buffer, 10, file);
        token = strtok(buffer, "\t");
        while(token!=NULL) {
            printf("%s \t", token);
            token = strtok(NULL, "\t");
        }
        printf("\n");
    }    
    
    exitValue = fclose(file);
    if(exitValue == 0) {
        printf("Se cerro el archivo correctamente.\n");
    }
    
    return 0;
}
