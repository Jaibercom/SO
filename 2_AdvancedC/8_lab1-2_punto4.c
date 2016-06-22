/*
 * Nombre       : lab1-2_punto4.c
 * Autor        : Juangui Restrepo
 * Descripcion  : Punto 4 del Taller de Laboratorio 1-2.
 *                Edad en meses y clasificacion.
 * Importancia  : Hacer uso de 'printf' y 'scanf' para imprimir y obtener
 *                informacion desde consola. Utilizar condicionales.
 *                Utilizar macros. Utilizar cadenas de caracteres.
 * Compilacion  : gcc -Wall lab1-2_punto4.c -o 4.out
 * Ejecucion    : ./4.out
 * Nota: Recuerde que existen 'infinitas' formas de construir un programa.
 * Conforme avance en el curso encontrara maneras mas optimas de
 * realizar estos ejercicios. Lo importante es que aplique
 * los conceptos aprendidos.
*/

/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, setbuf
#include <string.h>     // Manejo de strings

/* Definicion de macros y constantes. */
#define MAX_CHAR_CLASIF 11

/* Main function. */
int main() {
    /* Variables locales. */
    int edad;
    char clasificacion[MAX_CHAR_CLASIF];

    /* Obtener y almacenar la edad del usuario. */
    printf("Ingrese su edad en años: ");
    setbuf(stdin, NULL);
    scanf("%d", &edad);

    /* Obtener la clasificacion por edad. */
    if (edad >= 0 && edad <= 2) {
        strcpy(clasificacion, "Usted es un Bebe");
    } else if (edad >= 3 && edad <= 12) {
        strcpy(clasificacion, "Usted es un Ninho");
    } else if (edad >= 13 && edad <= 17){
        strcpy(clasificacion, "Usted es un Adolescente");
    } else if (edad >= 18) {
        strcpy(clasificacion, "Usted es un Adulto");
    } else {
        strcpy(clasificacion, "Usted es un No nacido");
    }

    /* Imprimir resultados en consola. */
    printf("|%-25s|%-25s|\n", "Clasificacion por edad", "Edad en meses");
    printf("|%25s|%25d|\n", clasificacion, edad*12);

    return 0;
}
