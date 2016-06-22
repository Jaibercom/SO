/*
 * Nombre       : lab1-2_punto2.c
 * Autor        : Juangui Restrepo
 * Descripcion  : Punto 2 del Taller de Laboratorio 1-2.
 *                Area y perimetro de un triangulo.
 * Importancia  : Hacer uso de 'printf' y 'scanf' para imprimir y obtener
 *                informacion desde consola.
 *                Realizar calculos matematicos basicos.
 * Compilacion  : gcc -Wall lab1-2_punto2.c -o 2.out -lm #lm para incluir la cabecera math.h
 * Ejecucion    : ./2.out
 * Nota: Recuerde que existen 'infinitas' formas de construir un programa.
 * Conforme avance en el curso encontrara maneras mas optimas de
 * realizar estos ejercicios. Lo importante es que aplique
 * los conceptos aprendidos.
*/

/* Inclusion de cabeceras o bibliotecas. */
#include <stdio.h>      // printf, scanf, setbuf, fflush
#include <math.h>       // sqrt, pow

/* Main function. */
int main() {
    /* Variables locales. */
    float base;
    float altura;
    float area;
    float perimetro;

    /* Obtener base y altura desde la consola. */

    printf("Ingrese la base del triangulo rectangulo: ");

    // Limpiar el buffer de la consola para no registrar datos residuales
    // cuando utilice la funcion 'scanf'.
    setbuf(stdin, NULL);

    // Note que 'scanf' requiere la direccion de las variables donde almacenara
    // los datos obtenidos por consola utilizando el caracter '&': &variable.
    scanf("%f", &base);

    printf("Ingrese la altura del triangulo rectangulo: ");

    // Limpie la consola con 'fflush' o 'setbuf' cada vez que vaya a
    // llamar a 'scanf' para evitar entradas extrañas.
    fflush(stdin);
    scanf("%f", &altura);

    /* Calcular el area y el perimetro. */
    area = (base * altura) / 2;
    perimetro = base + altura + sqrt(pow(base, 2) + pow(altura, 2));

    /* Imprimir resultados en consola. */
    // Note que 'printf' no requiere de la direccion de las variables.
    printf("El area del triangulo de base %.2f cm y altura %.2f cm es %.2f cm2\n",
            base, altura, area);
    printf("El perimetro del triangulo de base %.2f cm y altura %.2f cm es %.2f cm\n",
            base, altura, perimetro);

    return 0;
}
