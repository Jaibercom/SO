/*
 * Nombre       : lab1-2_punto5.c
 * Autor        : Juangui Restrepo
 * Descripcion  : Punto 5 del Taller de Laboratorio 1-2.
 *                Inicio por vocal.
 * Importancia  : Hacer uso de 'printf' y 'scanf' para imprimir y obtener
 *                informacion desde consola. Uso alternativo de switch.
 *                Utilizar cadenas de caracteres.
 * Compilacion  : gcc -Wall lab1-2_punto5.c -o 5.out
 * Ejecucion    : ./5.out
 * Nota: Recuerde que existen 'infinitas' formas de construir un programa.
 * Conforme avance en el curso encontrara maneras mas optimas de
 * realizar estos ejercicios. Lo importante es que aplique
 * los conceptos aprendidos.
*/

/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, fflush
#include <string.h>     // Manejo de strings

/* Definicion de macros y constantes. */
#define MAX_CHAR 20

/* Main function. */
int main() {
    /* Variables locales. */
    char palabra[MAX_CHAR];
    char primeraLetra;

    /* Obtener y almacenar la edad del usuario. */
    printf("Ingrese una palabra: ");
    fflush(stdin);
    // 'palabra' es una direccion a un arreglo de 20 caracteres.
    scanf("%s", palabra); // Por lo cual se omite el '&'.

    /* Obtener la primera letra de la palabra ingresada. */
    primeraLetra = palabra[0];

    /* Imprimir resultados en consola. */
    switch (primeraLetra) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("La palabra '%-10s' comienza por la vocal %c.\n", palabra, primeraLetra);
            break;
        default:
            printf("La palabra '%-10s' no comienza con una vocal.\n", palabra);
            break;
    }

    return 0;
}
