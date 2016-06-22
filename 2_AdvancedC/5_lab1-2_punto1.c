/*
 * Nombre       : lab1-2_punto1.c
 * Autor        : Juangui Restrepo
 * Descripcion  : Punto 1 del Taller de Laboratorio 1-2.
 *                Entero par o impar
 * Importancia  : Hacer uso de 'printf' y 'scanf' para imprimir y obtener
 *                informacion desde consola.
 * Compilacion  : gcc -Wall lab1-2_punto1.c -o 1.out
 * Ejecucion    : ./1.out
 * Nota: Recuerde que existen 'infinitas' formas de construir un programa.
 * Conforme avance en el curso encontrara maneras mas optimas de
 * realizar estos ejercicios. Lo importante es que aplique
 * los conceptos aprendidos.
*/

/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, setbuf

/* Main function. */
int main() {
    /* Variables locales. */
    int numero;
    int esImpar;

    /* Obtener numero desde la consola. */

    printf("Ingrese un numero: ");

    // Limpiar el buffer de la consola para no registrar datos residuales
    // cuando utilice la funcion 'scanf'.
    setbuf(stdin, NULL);

    // Note que 'scanf' requiere la direccion de las variables donde almacenara
    // los datos obtenidos por consola utilizando el caracter '&': &variable.
    scanf("%d", &numero);

    /* Determinar si el numero ingresado es par o impar. */
    esImpar = numero % 2; // Retorna 0 o 1

    /* Imprimir resultados en consola. */

    // Note que 'printf' no requiere de la direccion de las variables.
    printf("El numero %d es ", numero);

    // En C no existen los boolean. Utilice 0:False, OtroValor:True.
    if (esImpar) { // Si 'esImpar == 1'. Aun mejor: Si 'esImpar != 0'.
        printf("impar.\n");
    } else {       // esImpar == 0 en este caso.
        printf("par.\n");
    }

    /* Retornar '0' indica que el programa se ejecuto sin problemas. */
    return 0;
}
