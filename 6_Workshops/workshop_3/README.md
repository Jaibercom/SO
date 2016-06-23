# Taller 3 - Procesos

## A. Ping
[Archivos *ping.c (entrega parcial) y ping_sol.c (solución)*]  
Se tiene un programa en C que realiza un ping a un rango de máquinas (ping.c). Se desea implementar los siguientes cambios:

### 1. (50%)  
Modifique el programa para que paralelice el procesamiento. Se debe crear un proceso hijo que realice el respectivo ping a cada una de las maquinas.

### 2. (30%)  
El proceso padre debe esperar la ejecución de todos los hijos y calcular una estadistica del porcentaje de máquinas que han respondido y de máquinas que no responden.

### 3. (20%)  
Explique detalladamente el funcionamiento de la función `exec_ping`. ¿Para qué se utilizan las funciones sprintf, popen y strstr?

## B. Programa que compila y ejecuta a otro programa
[Archivo *spawn_sol.c y programa.c*]  
El profesor del curso requiere de un programa que compile y ejecute otro programa escrito en C.

### 1. (10%)  
El programa debe ejecutarse así: `$./eval3 programa.c`  

### 2. (10%)  
Se debe crear la función `spawn`, la cual debe crear un proceso hijo donde se invoque una función de la familia exec.

### 3. (25%)  
Use la función `spawn` para compilar el programa (programa.c).

### 4. (25%)  
Use la función `spawn` para ejecutar el programa previamente compilado, suponiendo que no hay errores en el proceso de compilación.

### Condiciones de entrega:
- Los programas deben ​`compilar sin errores`, ​`ejecutar sin problemas` y `no bloquear el equipo`. ​De lo contrario ​la nota es `cero`.

- La interpretación hace parte de la evaluación, `no se responden preguntas` durante el examen.
- Si se evidencia `algún tipo de copia` entre compañeros la nota para ambos es `cero`.
- Nombre del fichero a entregar: eval3_PrimerApellidoPrimerNombre.c.  

`No cumplir con estas condiciones influye en la calificación de su evaluación.`
