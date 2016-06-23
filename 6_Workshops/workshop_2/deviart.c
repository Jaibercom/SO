/*
 * Name         : deviant.c
 * Author       : Juangui Restrepo
 * Compilation  : gcc -Wall deviant.c -o deviant
 * Execution    : ./deviant 10
*/

/* Including headers or libraries. */
#include <stdio.h>      // printf, scanf, setbuf, fflush
#include <stdlib.h>     // malloc
#include <string.h>     // String handling

/* Definition of macros and constants. */
#define MAX_CHARS 15

/* Definition of structures. */
typedef struct {
    char realName[MAX_CHARS];
    char nickname[MAX_CHARS];
    char masterpiece[MAX_CHARS];
    int artworks;
} artist;

/* Declaration of functions (prototypes). */
void getOption(char *_option);
void registerArtists(artist *art, int *n, int max);
void showArtists(artist *art, int n);

/* Main function. */
int main(int argc, char *argv[]) {

    /* Local variables. */
    char option = 'x';
    int maxArtists = 0;
    int enlistedArtists = 0;
    artist *artists;

    // Validation: Number of arguments from console.
    if (argc != 2) {
        printf("Error: Numero de parametros invalido.\nDebe iniciar asi: ./deviart.out <numero max artistas>\n");
		exit(0);
    }

    maxArtists = atoi(argv[1]);

    if (maxArtists <= 0) {
        printf("Error: El parametro ingresado debe ser mayor a cero.\n");
		exit(0);
    }

    artists = (artist *)malloc(sizeof(artist) * maxArtists);

    do {
        getOption(&option);
        switch (option) {
            case 'a':
                registerArtists(artists, &enlistedArtists, maxArtists);
                break;
            case 'b':
				showArtists(artists, enlistedArtists);
                break;
            case 'q':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("La opcion '%c' no es valida. Volviendo al menu.\n", option);
                break;
        }
    } while(option != 'q');

    /* Free memory. */
    free(artists);

    return 0;
}

/* Implementation of functions. */

void getOption(char *_option) {
  printf("\nDeviArt\n");
  printf("\ta) Registrar artistas\n");
  printf("\tb) Ver lista de artistas\n");
  printf("\tq) Salir del programa\n");
  printf("Seleccione una opcion: ");
  setbuf(stdin, NULL);
  scanf("\n%c", _option);
}

void registerArtists(artist *art, int *n, int max) {
    int i = 0;
    int newArtists = 0;

    printf("Ingrese el numero de artistas a registrar: ");
    setbuf(stdin, NULL);
    scanf("%d", &newArtists);

    if (*n + newArtists > max) {
        printf("No es posible registrar %d artistas.\n", newArtists);
        printf("La capacidad maxima es %d y actualmente estan registrados %d.\n", max, *n);
        return;
       }

       for (i = *n; i < *n + newArtists; i++) {
           printf("\nNombre del artista #%d: ", i + 1);
           setbuf(stdin, NULL);
           scanf(" %s", art->realName);

           printf("\nNickname: ");
           setbuf(stdin, NULL);
           scanf(" %s", art->nickname);

           printf("\nObra maestra: ");
           setbuf(stdin, NULL);
           scanf(" %s", art->masterpiece);

           printf("\nNumero de obras realizadas: ");
           setbuf(stdin, NULL);
           scanf(" %d", &art->artworks);

           art++;
       }
       *n += newArtists;
       printf("\nSe han registrado %d artistas en la lista.\n", newArtists);
}

void showArtists(artist *art, int n) {
    int i = 0;
    if (n <= 0) {
        printf("No se han registrado artistas aun\n");
        return;
    }
	printf("\nLista de artistas:\n");
    printf("|%-15s|%-15s|%-15s|%-16s|\n", "Nombre", "Nick", "Obra Maestra", "Obras realizadas");
    for (i = 0; i < n; i++) {
        printf("|%-15s|%-15s|%-15s|%-16d|\n", art->realName, art->nickname, art->masterpiece, art->artworks);
        art++;
    }
}
