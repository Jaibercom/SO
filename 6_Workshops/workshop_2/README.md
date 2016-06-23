# Taller 2 - C Avanzado

## A. Nómina v.2
[Archivos *nomina+.c, factory+.c  y factory_filetxt.c*]  
La empresa ​EMPRENDOR S.A. requiere de un programa en C que le permita crear una lista con sus trabajadores y sus salarios como se muestra a continuación:

| Nombre del trabajador | Salario    |
|:----------------------|:-----------|
| Camilo                | 650000.00  |
| Mateo                 | 600000.00  |
| Carlos                | 750000.00  |
| Manuel                | 800000.00  |
| `Total`               | 2800000.00 |

Diseñe un programa que cumpla con los siguientes requisitos:
### 1. Menú de opciones (20%)  
El programa debe implementar un menú con las siguientes opciones:  
###### MENÚ DE OPCIONES  
a) Registrar trabajadores.  
b) Obtener el pago total.  
q) Mostrar la lista y salir del programa.  
Seleccione una opción: a  

### 2. Registrar trabajadores (40%)  
Implementar la opción “a”: crear una función que solicite el número de trabajadores a registrar, el nombre y el salario de cada trabajador. ​
Utilice memoria dinámica ​para
almacenar esta información.  

### 3. Obtener el pago total (20%)  
Implementar la opción “b”: crear una función que calcule la suma de todos los salarios y muestre el pago total que debe hacer la empresa a los trabajadores.  

### 4. Mostrar la lista y salir (20%)  
Implementar la opción “q”: muestre la nueva lista y finalice el programa. La lista debe tener el siguiente formato:

##### Lista de trabajadores
###### EMPRENDOR S.A.
###### NIT. xxxxxxxxx

| Nombre del trabajador | Salario    |
|:----------------------|:-----------|
| Camilo                | 650000.00  |
| Mateo                 | 600000.00  |
| Carlos                | 750000.00  |
| Manuel                | 800000.00  |
| `Total`               | 2800000.00 |
Saliendo del programa...

### Nota:
- El número máximo de trabajadores que se pueden incluir en la lista debe ser pasado al programa como un argumento por consola.
- Para facilitar el diseño del programa, suponga que el nombre de un trabajador puede tener como máximo 50 caracteres y el usuario nunca excede este tamaño.
- El programa debe utilizar estructuras y manipulación de archivos.
- Se proponen las siguientes funciones:  
//Muestra el menú y obtiene la opción seleccionada.  
getOption(...);  
// Registra a los trabajadores y sus salarios en memoria dinámica.  
createList(...);  
// Obtiene la suma de todos los salarios.  
getTotal(...);  
// Muestra la lista de trabajadores con un formato tabulado.  
showList(...);  

## B. Mares v.2
[Archivo *mares+.c*]  
Diseñe un programa que permita calcular el promedio de notas de n materias.
El programa debe obtener los datos desde un archivo que debe ser pasado como argumento por consola.

## C. Banco
[Archivo *banco.c*]
Diseñe un programa que permita registrar a un nuevo cliente ingresando su nombre, número de cuenta y saldo de apertura.  
Al finalizar el registro el programa deberá imprimir la información del nuevo cliente junto al plan que le fue asignado.
Los planes disponibles son los siguientes:
- `Miniahorrador:` El monto de apertura es menor a 100000.
- `PreferencialProX:` El monto de apertura es mayor a 200000.
- `Ahorregular:` El monto de apertura esta entre 100000 y 200000.

## D. Deviart
[Archivo *deviart.c*]
La página web sobre arte y diseño `Deviart` requiere un programa en C que le permita registrar a sus usuarios.  
El programa debe desplegar un menú de opciones que permita:
- Registrar un artista: Permite registrar n artistas ingresando el nombre real, seudonimo, el nombre de su obra mas importante y el número total de obras artisticas realizada por cada artista.
- Mostrar la información de todos los artistas en un formato tabulado.
- Salir del programa.

## E. Números complejos
[Archivo *complejos.c*]
Diseñe un programa en C que permita sumar, restar y multiplicar 2 números complejos.

## F. Leer diferentes formatos
[Archivo *leer_tabulaciones.c*]
Cree un programa en C que lea archivos con datos separados por tabulaciones.  
Como ejercicio propuesto cree un programa que pueda leer archivos con los formatos mostrados en el Laboratorio (csv, json, txt, entre otros).

### Condiciones de entrega:
- Los programas deben ​`compilar sin errores`, ​`ejecutar sin problemas` y `no bloquear el equipo`. ​De lo contrario ​la nota es `cero`.

- La interpretación hace parte de la evaluación, `no se responden preguntas` durante el examen.
- Si se evidencia `algún tipo de copia` entre compañeros la nota para ambos es `cero`.
- Nombre del fichero a entregar: eval2_PrimerApellidoPrimerNombre.c.  

`No cumplir con estas condiciones influye en la calificación de su evaluación.`
