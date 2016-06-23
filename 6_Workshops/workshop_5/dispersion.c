/*
================================================================================
Name         : TallerSincronizacion.c
Author       : Juan Guillermo Restrepo Pineda
Version      : 1.0
Compilation  : gcc -Wall TallerSincronizacion.c -o sincro.out -lpthread -lm -lrt
Execution    : ./sincro.out notas.csv
================================================================================
*/

/* Incluyendo cabeceras o bibliotecas */
#include <stdio.h>          /* printf()                 */
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait()..   */
#include <fcntl.h>          /* O_CREAT, O_EXEC          */
#include <pthread.h>        /* sem_init(), sem_post(), sem_wait(), sem_destroy() */
#include <math.h>           /* powf(), sqrtf()          */
#include <string.h>         /* strtok()                 */
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/mman.h>

/* Declaracion de funciones */
void verificarArgumentos(int numeroArgumentos, char**argumentos);
FILE* abrirArchivo(char* nombreDeArchivo);
int obtenerNumeroDeNotas(FILE* archivo);
void obtenerNotas(FILE* archivo, int numeroNotas, float* listaNotas);
void imprimirNotas(float* listaNotas, int numeroNotas);
float calcularPromedio(int numeroNotas, float* listaNotas);
float calcularDesviacion(int numeroNotas, float* listaNotas, float promedio);
void cerrarArchivo(FILE* archivo);

/* Main */
int main(int argc, char *argv[]) {

    FILE* archivo;
    int numeroNotas;
    float* listaNotas;
    sem_t *sem1;
    sem_t *sem2;
    pid_t pid1, pid2;
    int descriptorMC;
    void *direccionMC;
    const char *nombreMC = "Mi memoria compartido";
    float promedio;
    float desviacion;

    // Se validan los datos
    verificarArgumentos(argc, argv);

    // Se abre el archivo
    archivo = abrirArchivo(argv[1]);
    printf("Se abre el archivo %s exitosamente\n", argv[1]);

    // Se lee el archivo obteniendo las notas
    numeroNotas = obtenerNumeroDeNotas(archivo);
    listaNotas = (float *) malloc (sizeof(float) * numeroNotas);
    obtenerNotas(archivo, numeroNotas, listaNotas);
    printf("Se obtiene un total de %d notas desde archivo\n", numeroNotas);
    //imprimirNotas(listaNotas, numeroNotas);

    // COMUNICACION Y SINCRONIZACION
    // -------------------------------------------------------------------------

    // Se crean los procesos solicitados: DOS para nuestro caso
    // Se crea el primer proceso hijo
    pid1 = fork();
    if (pid1 < 0) { // Caso de error: No se puede crear un proceso hijo
        printf ("Error: No fue posible crear al primer proceso hijo\n");
        exit(-1);
    } else if(pid1 == 0) { // Primer proceso hijo

        printf("Nuevo proceso (1): Calcular el promedio\n");

        // Se calcula el promedio de las notas
        promedio = calcularPromedio(numeroNotas, listaNotas);
        printf("Promedio: %.3f\n", promedio);
        exit(0); // <-------------------------- IMPORTANTE

    } else { // Vuelve al proceso padre

        // Se crea el segundo proceso hijo
        pid2 = fork();
        if (pid2 < 0) {
            printf ("Error: No fue posible crear al segundo proceso hijo\n");
            exit(-1);
        } else if (pid2 == 0) { // Segundo proceso hijo

            printf("Nuevo proceso (2): Calcular la desviacion estandar\n");

            // Se calcula la desviacion estandar de las notas
            desviacion = calcularDesviacion(numeroNotas, listaNotas, promedio);
            printf("Desviacion estandar: %.5f\n", desviacion);
            exit(0); // <-------------------------- IMPORTANTE

        } else { // Vuelve al proceso padre
            printf("Proceso padre: Todos mis hijos terminaron\n");
        }
    }

    // -------------------------------------------------------------------------

    // Se libera la memoria dinamica
    free(listaNotas);
    printf("Se libera la memoria dinamica\n");

    // Se cierra el archivo
    cerrarArchivo(archivo);
    printf("Se cierra el archivo %s exitosamente\n", argv[1]);

    // Finaliza el programa
    printf("Finaliza el programa %s...\n", argv[0]);
    return 0;
}

/* Implementacion de funciones */

// Verifica si los argumentos por consola son los esperados por el programa
void verificarArgumentos(int numeroArgumentos, char **argumentos){
	if(numeroArgumentos != 2) { // Falla la validación
		printf("Error: Numero de argumentos no valido\n");
        printf("Se esperaba la siguiente entrada:\n");
    	printf(" %s notas.csv \n", argumentos[0]);
		exit(1);
	}
    // Confirmacion: Se pasa la validación
    printf("Se han validado los datos ingresados\n");
    printf("---- Nombre del programa: %s\n", argumentos[0]);
    printf("---- Nombre del archivo: %s\n", argumentos[1]);
}

// Abre el archivo de notas en modo sólo lectura
FILE* abrirArchivo(char* nombreDeArchivo){
	FILE* archivo = fopen(nombreDeArchivo,"r");
	if(archivo == NULL) { // Fallo al abrir el archivo
		printf("Error: No fue posible abrir el archivo %s", nombreDeArchivo);
		exit(1);
	}
	return archivo;
}

// Lee el archivo y obtiene el numero de notas
int obtenerNumeroDeNotas(FILE* archivo){
    char bufferLinea[256];
    char *token;
    int numeroNotas = 0;

    while (fgets (bufferLinea, sizeof(bufferLinea), archivo)) {
        token = strtok(bufferLinea, ";");
        while( token != NULL ) {
            numeroNotas++;
            token = strtok(NULL, ";");
        }
    }
    rewind(archivo);
    return numeroNotas;
}

// Lee el archivo y obtiene las notas
void obtenerNotas(FILE* archivo, int numeroNotas, float* listaNotas){
    char bufferLinea[256];
    char *token;

    while (fgets (bufferLinea, sizeof(bufferLinea), archivo)) {
        token = strtok(bufferLinea, ";");
        while( token != NULL ) {
            *listaNotas = atof(token);
            token = strtok(NULL, ";");
            listaNotas++;
        }
    }
    rewind(archivo);
}

// Verifica que las notas esten en memoria dinamica
void imprimirNotas(float* listaNotas, int numeroNotas) {
    int i = 0;
    printf("Listado de notas:\n");
    for (i = 0; i < numeroNotas; i++) {
        printf("---- Nota (%d): %.1f\n", i+1, *listaNotas);
        listaNotas++;
    }
}

// Calcula el promedio de notas
float calcularPromedio(int numeroNotas, float* listaNotas){
    float promedio = 0;
    float sumatoria = 0;
	int i;

	for(i=0; i<numeroNotas; i++){
		sumatoria += *listaNotas;
		listaNotas++;
	}
	promedio = sumatoria/numeroNotas;
	return promedio;
}

// Calcula la desviacion estandar de las notas
float calcularDesviacion(int numeroNotas, float* listaNotas, float promedio){
    float desviacion = 0;
    float sumatoria = 0;
    float varianza = 0;
	int i;

	for(i=0; i<numeroNotas; i++){
		sumatoria += powf((*listaNotas - promedio), 2);
		listaNotas++;
	}
	varianza = sumatoria/(numeroNotas - 1);
    desviacion = sqrtf(varianza);
	return desviacion;
}

// Cierra el archivo de notas
void cerrarArchivo(FILE* archivo){
	int salida = fclose(archivo);
	if(salida!=0) { // Fallo al cerrar el archivo
		printf("Error: No fue posible cerrar el archivo");
	}
}
