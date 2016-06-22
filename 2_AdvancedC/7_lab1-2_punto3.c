/*
 * Nombre       : lab1-2_punto3.c
 * Autor        : Juangui Restrepo
 * Descripcion  : Punto 3 del Taller de Laboratorio 1-2.
 *                Pacientes.
 * Importancia  : Hacer uso de 'printf' y 'scanf' para imprimir y obtener
 *                informacion desde consola. Utilizar arreglos, ciclos y macros.
 * Compilacion  : gcc -Wall lab1-2_punto3.c -o 3.out
 * Ejecucion    : ./3.out
 * Nota: Recuerde que existen 'infinitas' formas de construir un programa.
 * Conforme avance en el curso encontrara maneras mas optimas de
 * realizar estos ejercicios. Lo importante es que aplique
 * los conceptos aprendidos.
*/

/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, fflush

/* Definicion de macros y constantes. */
#define NUM_PACIENTES 5
#define MAX_CHAR_NOMBRE 7

/* Main function. */
int main() {
    /* Variables locales. */
    int i;
    float estaturas[NUM_PACIENTES];

    /* Obtener y almacenar las estaturas de los pacientes. */
    for (i = 0; i < NUM_PACIENTES; i++) {
        printf("Ingrese la estatura del paciente #%d: ", i+1);
        fflush(stdin);
        scanf("%f", &estaturas[i]);
    }

    /* Imprimir resultados en consola. */
    for (i = 0; i < NUM_PACIENTES; i++) {
        printf("El paciente #%d mide %.2f metros\n",
            i+1, estaturas[i]);
    }

    return 0;
}
