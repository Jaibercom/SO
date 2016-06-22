/*
 * EJEMPLO DE USO DE LA PLANTILLA VACIA, VERSION 1.
 * Name         : uso_plantilla_v1.c
 * Author       : Juangui Restrepo.
 * Description  : Uso de plantilla y algunos temas vistos.
 *                Suma 2 a dos numeros ingresados.
 * Compilation  : gcc -Wall uso_plantilla_v1.c -o 1.out
 * Execution    : ./1.out
*/

/* Incluir cabeceras o bibliotecas. */
#include <stdio.h>                              // printf, scanf, setbuf, fflush
#include <stdlib.h>                             // malloc, free

/* Definicion de macros y constantes. */
                                                // Ejemplo de:
#define UNO 1                                   // Constante
#define SUMAR(X) (X+1)                          // Macro

/* Declaracion de funciones. */                 // Declarar funciones
void obtenerNumeros(int *num1, int *num2);
int sumarUno(int num);
void mostrarResultados(int *res2);

/* Variables globales. */                       // Declarar var globales
int resultado1;

/* Main function. */
int main() {
    
    /* Variables locales. */
    int num1;                                   // Entero
    int *num2;                                  // Apuntador
    int resultado2;                             // Variable local
    
    /* Asignar espacio en memoria dinamica. */
    num2 = (int *) malloc(sizeof(int));         // Asignacion de memoria
    
    /* Obtener informacion. */
    obtenerNumeros(&num1, num2);                // Paso por referencia
    
    /* Hacer operaciones. */
    resultado1 = sumarUno(num1);                // Paso por valor
    resultado2 = sumarUno(*num2);               // Paso por valor
    
    /* Mostrar resultados. */
    mostrarResultados(&resultado2);              // Otro llamado a una funcion, paso por referencia
    
    /* Liberar memoria y finalizar. */
    free(num2);                                 // Liberar memoria
    return 0;
}

/* Implementacion de funciones. */
void obtenerNumeros(int *num1, int *num2) {
    printf("Ingrese primer numero: ");          // Salida en consola
    setbuf(stdin, NULL);                        // Limpiar consola: Forma 1
    scanf("%d", num1);                          // Entrada en consola
    
    printf("Ingrese segundo numero: ");
    fflush(stdin);                              // Limpiar consola: Forma 2
    scanf("%d", num2);
}

int sumarUno(int num) {
    int res = SUMAR(num) + UNO;                  // Uso de macros y constantes
    return res;                                  // Funcion con retorno
}

void mostrarResultados(int *res2) {
    printf("Resultado 1: %d\n", resultado1);     // Variable global
    printf("Resultado 2: %d", *res2);
}
